#include "parser.h"

#include <algorithm>
#include <cctype>
#include <regex>
#include <sstream>
#include <stdexcept>

namespace {
std::string trim(const std::string& s) {
    std::size_t start = 0;
    while (start < s.size() && std::isspace(static_cast<unsigned char>(s[start]))) {
        ++start;
    }
    std::size_t end = s.size();
    while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1]))) {
        --end;
    }
    return s.substr(start, end - start);
}

std::string collapse_spaces(const std::string& s) {
    std::string out;
    out.reserve(s.size());
    bool prev_space = false;
    for (char c : s) {
        if (std::isspace(static_cast<unsigned char>(c))) {
            if (!prev_space) {
                out.push_back(' ');
            }
            prev_space = true;
        } else {
            out.push_back(c);
            prev_space = false;
        }
    }
    return trim(out);
}

std::string to_lower_copy(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    return s;
}

std::vector<std::string> split_csv(const std::string& input) {
    std::vector<std::string> out;
    std::stringstream ss(input);
    std::string token;
    while (std::getline(ss, token, ',')) {
        const auto t = trim(token);
        if (!t.empty()) {
            out.push_back(t);
        }
    }
    return out;
}

std::vector<std::string> split_and(const std::string& input) {
    std::vector<std::string> out;
    std::regex and_re(R"(\s+AND\s+)", std::regex::icase);
    std::sregex_token_iterator it(input.begin(), input.end(), and_re, -1);
    std::sregex_token_iterator end;
    for (; it != end; ++it) {
        const auto t = trim(*it);
        if (!t.empty()) {
            out.push_back(t);
        }
    }
    return out;
}

FilterPredicate parse_filter_predicate(const std::string& pred) {
    std::regex re(R"(^([a-zA-Z_][\w]*)\.([a-zA-Z_][\w]*)\s*(=|<=|>=|<|>)\s*(.+)$)");
    std::smatch m;
    if (!std::regex_match(pred, m, re)) {
        throw OptimizerException("Invalid filter predicate: " + pred);
    }

    FilterPredicate f;
    f.table = to_lower_copy(m[1].str());
    f.column = to_lower_copy(m[2].str());
    f.op = m[3].str();
    f.value = trim(m[4].str());
    return f;
}

JoinPredicate parse_join_predicate(const std::string& pred) {
    std::regex re(R"(^([a-zA-Z_][\w]*)\.([a-zA-Z_][\w]*)\s*=\s*([a-zA-Z_][\w]*)\.([a-zA-Z_][\w]*)$)");
    std::smatch m;
    if (!std::regex_match(pred, m, re)) {
        throw OptimizerException("Invalid join predicate: " + pred);
    }

    JoinPredicate j;
    j.left_table = to_lower_copy(m[1].str());
    j.left_column = to_lower_copy(m[2].str());
    j.right_table = to_lower_copy(m[3].str());
    j.right_column = to_lower_copy(m[4].str());
    return j;
}
}  // namespace

Query QueryParser::parse(const std::string& sql) const {
    std::string cleaned = collapse_spaces(sql);
    if (!cleaned.empty() && cleaned.back() == ';') {
        cleaned.pop_back();
    }

    std::regex query_re(R"(^SELECT\s+(.+)\s+FROM\s+(.+?)(?:\s+WHERE\s+(.+))?$)", std::regex::icase);
    std::smatch m;
    if (!std::regex_match(cleaned, m, query_re)) {
        throw OptimizerException("Unsupported query format. Use SELECT ... FROM ... [WHERE ...].");
    }

    Query query;
    for (const auto& col : split_csv(m[1].str())) {
        query.select_columns.push_back(to_lower_copy(col));
    }

    std::string from_clause = m[2].str();
    std::regex join_re(R"(\s+JOIN\s+)", std::regex::icase);
    std::sregex_token_iterator join_it(from_clause.begin(), from_clause.end(), join_re, -1);
    std::sregex_token_iterator end;

    std::vector<std::string> join_parts;
    for (; join_it != end; ++join_it) {
        join_parts.push_back(trim(*join_it));
    }
    if (join_parts.empty()) {
        throw OptimizerException("FROM clause is empty.");
    }

    std::regex base_re(R"(^([a-zA-Z_][\w]*)(?:\s+AS\s+[a-zA-Z_][\w]*)?$)", std::regex::icase);
    std::smatch base_match;
    if (!std::regex_match(join_parts[0], base_match, base_re)) {
        throw OptimizerException("Invalid base table in FROM clause.");
    }
    query.tables.push_back(to_lower_copy(base_match[1].str()));

    for (std::size_t i = 1; i < join_parts.size(); ++i) {
        std::regex part_re(R"(^([a-zA-Z_][\w]*)(?:\s+AS\s+[a-zA-Z_][\w]*)?\s+ON\s+(.+)$)", std::regex::icase);
        std::smatch part_match;
        if (!std::regex_match(join_parts[i], part_match, part_re)) {
            throw OptimizerException("Invalid JOIN clause: " + join_parts[i]);
        }

        query.tables.push_back(to_lower_copy(part_match[1].str()));
        query.joins.push_back(parse_join_predicate(trim(part_match[2].str())));
    }

    if (m.size() >= 4 && m[3].matched) {
        const std::string where_clause = m[3].str();
        for (const auto& pred : split_and(where_clause)) {
            // A predicate with table.column = table.column is treated as a join predicate.
            if (pred.find('=') != std::string::npos && pred.find('.') != std::string::npos) {
                try {
                    query.joins.push_back(parse_join_predicate(pred));
                    continue;
                } catch (const std::exception&) {
                    // Fall back to filter parsing.
                }
            }
            query.filters.push_back(parse_filter_predicate(pred));
        }
    }

    return query;
}
