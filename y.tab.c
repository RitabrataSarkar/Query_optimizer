/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "sql_parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "sql_parser.h"

void yyerror(const char *s);
int yylex(void);
extern FILE *yyin;

RelNode *result = NULL;

#line 85 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    INT_LITERAL = 259,             /* INT_LITERAL  */
    FLOAT_LITERAL = 260,           /* FLOAT_LITERAL  */
    STRING_LITERAL = 261,          /* STRING_LITERAL  */
    SELECT = 262,                  /* SELECT  */
    FROM = 263,                    /* FROM  */
    WHERE = 264,                   /* WHERE  */
    JOIN = 265,                    /* JOIN  */
    ON = 266,                      /* ON  */
    AS = 267,                      /* AS  */
    AND = 268,                     /* AND  */
    OR = 269,                      /* OR  */
    NOT = 270,                     /* NOT  */
    EQ = 271,                      /* EQ  */
    LT = 272,                      /* LT  */
    GT = 273,                      /* GT  */
    LE = 274,                      /* LE  */
    GE = 275,                      /* GE  */
    NE = 276,                      /* NE  */
    PLUS = 277,                    /* PLUS  */
    MULTIPLY = 278                 /* MULTIPLY  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 15 "sql_parser.y"

    int intval;
    float floatval;
    char *strval;
    struct Column *col;
    struct Table *tbl;
    struct Condition *cond;
    struct RelNode *node;

#line 168 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_INT_LITERAL = 4,                /* INT_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 5,              /* FLOAT_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 6,             /* STRING_LITERAL  */
  YYSYMBOL_SELECT = 7,                     /* SELECT  */
  YYSYMBOL_FROM = 8,                       /* FROM  */
  YYSYMBOL_WHERE = 9,                      /* WHERE  */
  YYSYMBOL_JOIN = 10,                      /* JOIN  */
  YYSYMBOL_ON = 11,                        /* ON  */
  YYSYMBOL_AS = 12,                        /* AS  */
  YYSYMBOL_AND = 13,                       /* AND  */
  YYSYMBOL_OR = 14,                        /* OR  */
  YYSYMBOL_NOT = 15,                       /* NOT  */
  YYSYMBOL_EQ = 16,                        /* EQ  */
  YYSYMBOL_LT = 17,                        /* LT  */
  YYSYMBOL_GT = 18,                        /* GT  */
  YYSYMBOL_LE = 19,                        /* LE  */
  YYSYMBOL_GE = 20,                        /* GE  */
  YYSYMBOL_NE = 21,                        /* NE  */
  YYSYMBOL_PLUS = 22,                      /* PLUS  */
  YYSYMBOL_MULTIPLY = 23,                  /* MULTIPLY  */
  YYSYMBOL_24_ = 24,                       /* ','  */
  YYSYMBOL_25_ = 25,                       /* '.'  */
  YYSYMBOL_26_ = 26,                       /* '*'  */
  YYSYMBOL_27_ = 27,                       /* '('  */
  YYSYMBOL_28_ = 28,                       /* ')'  */
  YYSYMBOL_29_ = 29,                       /* '-'  */
  YYSYMBOL_YYACCEPT = 30,                  /* $accept  */
  YYSYMBOL_start = 31,                     /* start  */
  YYSYMBOL_query_stmt = 32,                /* query_stmt  */
  YYSYMBOL_column_list = 33,               /* column_list  */
  YYSYMBOL_column = 34,                    /* column  */
  YYSYMBOL_dotted_identifier = 35,         /* dotted_identifier  */
  YYSYMBOL_join_list = 36,                 /* join_list  */
  YYSYMBOL_join_table = 37,                /* join_table  */
  YYSYMBOL_table_item = 38,                /* table_item  */
  YYSYMBOL_subquery = 39,                  /* subquery  */
  YYSYMBOL_table_ref = 40,                 /* table_ref  */
  YYSYMBOL_opt_where_clause = 41,          /* opt_where_clause  */
  YYSYMBOL_where_clause = 42,              /* where_clause  */
  YYSYMBOL_join_condition = 43,            /* join_condition  */
  YYSYMBOL_condition = 44,                 /* condition  */
  YYSYMBOL_comparison_expr = 45            /* comparison_expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   159

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  150

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   278


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      27,    28,    26,     2,    24,    29,    25,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    49,    49,    55,    64,    67,    73,    78,    85,    89,
      99,   102,   108,   114,   120,   123,   129,   133,   140,   144,
     149,   166,   169,   175,   181,   187,   190,   193,   196,   199,
     205,   212,   217,   222,   228,   235,   242,   249,   256,   263,
     268,   273,   278,   283,   288,   293,   298,   303,   308,   314,
     320,   326,   332,   338,   344,   350,   356,   362,   370,   376,
     382,   388,   394,   401,   407,   413,   419,   425,   432,   438,
     444,   450,   456
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "INT_LITERAL", "FLOAT_LITERAL", "STRING_LITERAL", "SELECT", "FROM",
  "WHERE", "JOIN", "ON", "AS", "AND", "OR", "NOT", "EQ", "LT", "GT", "LE",
  "GE", "NE", "PLUS", "MULTIPLY", "','", "'.'", "'*'", "'('", "')'", "'-'",
  "$accept", "start", "query_stmt", "column_list", "column",
  "dotted_identifier", "join_list", "join_table", "table_item", "subquery",
  "table_ref", "opt_where_clause", "where_clause", "join_condition",
  "condition", "comparison_expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-44)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       1,     9,    22,   -44,    17,    -4,   -44,   -44,     2,     0,
       9,   -44,   -44,    21,    12,     1,    -3,   -44,   -44,   -44,
     -44,    64,   -44,    66,    42,    -2,     0,     0,   -44,   -44,
     -44,   -44,    20,    46,    -2,    -1,    31,   -44,    72,   -44,
     -44,   -44,    81,   116,   -44,    95,     5,    -2,    -2,    -2,
     -44,    18,   116,   -44,   -44,   109,   -44,    31,    88,    92,
      96,   100,   104,   108,   117,   119,   120,    43,   101,   -44,
     -44,   -44,   102,   -44,   -44,   -44,   103,   -44,   -44,   -44,
     105,   -44,   -44,   -44,   106,   -44,   -44,   -44,   107,   -44,
     -44,   -44,    32,    62,    98,   121,   116,   116,   116,   116,
     116,   116,   125,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,    57,    21,    21,    21,
      21,    21,    21,   -44,   -44,   -44,   -44,   -44,   -44,   -44,
     -44,   -44,   -44,   -44,   -44,   -44,   -44,   124,   143,    70,
     144,   145,   146,   147,   148,   -44,   -44,   -44,   -44,   -44
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     0,     0,     4,     1,     0,     0,
       0,     8,     7,     6,    18,     0,    21,    10,    15,    14,
       5,     0,    20,     0,     0,     0,     0,     0,     3,    22,
       9,    19,     0,     0,     0,     0,    23,    25,     0,    13,
      11,    17,     0,     0,    28,     0,     0,     0,     0,     0,
      16,     0,     0,    29,    26,    27,    12,    24,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    31,
      32,    33,     0,    39,    44,    53,     0,    40,    45,    54,
       0,    41,    46,    55,     0,    42,    47,    56,     0,    43,
      48,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    30,    34,    35,
      36,    37,    38,    72,    69,    68,    71,    70,    67,    64,
      63,    66,    65,    49,    50,    51,    52,     0,     0,     0,
       0,     0,     0,     0,     0,    62,    59,    58,    61,    60
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -44,   -44,   142,   -44,   149,   -43,   -44,   -44,   -16,   -44,
     -44,   -44,   -44,   -44,   -18,   -44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     5,     6,    13,    16,    38,    17,    18,
      19,    28,    29,    56,    36,    37
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      51,    33,    45,    14,     9,    11,    25,    26,     1,    67,
      39,    40,     4,    34,    34,    22,    44,    46,    47,    48,
      10,    27,     7,    41,    23,    35,    35,    15,    12,    54,
      55,    57,    42,    53,    58,    59,    60,    61,    62,    63,
      64,    65,     8,    21,    47,    48,    21,    66,   102,   103,
     104,   105,   106,   117,   118,   119,   120,   121,   122,    58,
      59,    60,    61,    62,    63,    64,    95,    30,    21,    31,
      32,    43,    66,   107,   108,   109,   110,   111,   107,   108,
     109,   110,   111,    49,    50,   137,   140,   141,   142,   143,
     144,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,   112,   113,   114,   115,    11,
      52,    92,    47,    93,    94,   116,    96,    97,    98,   123,
      99,   100,   101,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   138,   139,   145,   146,
     147,   148,   149,     0,     0,     0,     0,    24,     0,    20
};

static const yytype_int8 yycheck[] =
{
      43,     3,     3,     3,     8,     3,     9,    10,     7,    52,
      26,    27,     3,    15,    15,     3,    34,    35,    13,    14,
      24,    24,     0,     3,    12,    27,    27,    27,    26,    47,
      48,    49,    12,    28,    16,    17,    18,    19,    20,    21,
      22,    23,    25,    25,    13,    14,    25,    29,    16,    17,
      18,    19,    20,    96,    97,    98,    99,   100,   101,    16,
      17,    18,    19,    20,    21,    22,    23,     3,    25,     3,
      28,    25,    29,    16,    17,    18,    19,    20,    16,    17,
      18,    19,    20,    11,     3,    28,    16,    17,    18,    19,
      20,     3,     4,     5,     6,     3,     4,     5,     6,     3,
       4,     5,     6,     3,     4,     5,     6,     3,     4,     5,
       6,     3,     4,     5,     6,    17,    18,    19,    20,     3,
      25,     4,    13,     4,     4,     4,    25,    25,    25,     4,
      25,    25,    25,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,    22,     4,     4,     4,
       4,     4,     4,    -1,    -1,    -1,    -1,    15,    -1,    10
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,    31,    32,     3,    33,    34,     0,    25,     8,
      24,     3,    26,    35,     3,    27,    36,    38,    39,    40,
      34,    25,     3,    12,    32,     9,    10,    24,    41,    42,
       3,     3,    28,     3,    15,    27,    44,    45,    37,    38,
      38,     3,    12,    25,    44,     3,    44,    13,    14,    11,
       3,    35,    25,    28,    44,    44,    43,    44,    16,    17,
      18,    19,    20,    21,    22,    23,    29,    35,     3,     4,
       5,     6,     3,     4,     5,     6,     3,     4,     5,     6,
       3,     4,     5,     6,     3,     4,     5,     6,     3,     4,
       5,     6,     4,     4,     4,    23,    25,    25,    25,    25,
      25,    25,    16,    17,    18,    19,    20,    16,    17,    18,
      19,    20,    17,    18,    19,    20,     4,    35,    35,    35,
      35,    35,    35,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,    28,    22,     4,
      16,    17,    18,    19,    20,     4,     4,     4,     4,     4
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    30,    31,    32,    33,    33,    34,    34,    35,    35,
      36,    36,    36,    37,    38,    38,    39,    39,    40,    40,
      40,    41,    41,    42,    43,    44,    44,    44,    44,    44,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     5,     1,     3,     3,     3,     1,     3,
       1,     3,     5,     1,     1,     1,     5,     4,     1,     3,
       2,     0,     1,     2,     1,     1,     3,     3,     2,     3,
       7,     5,     5,     5,     7,     7,     7,     7,     7,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     7,
       7,     7,     7,     5,     5,     5,     5,     5,    11,    11,
      11,    11,    11,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* start: query_stmt  */
#line 49 "sql_parser.y"
                  {
    result = (yyvsp[0].node);
}
#line 1283 "y.tab.c"
    break;

  case 3: /* query_stmt: SELECT column_list FROM join_list opt_where_clause  */
#line 55 "sql_parser.y"
                                                       {
        (yyval.node) = create_project_node((yyvsp[-1].node), (yyvsp[-3].col));
        if ((yyvsp[0].cond) != NULL) {
            (yyval.node) = create_select_node((yyval.node), (yyvsp[0].cond));
        }
    }
#line 1294 "y.tab.c"
    break;

  case 4: /* column_list: column  */
#line 64 "sql_parser.y"
           {
        (yyval.col) = (yyvsp[0].col);
    }
#line 1302 "y.tab.c"
    break;

  case 5: /* column_list: column_list ',' column  */
#line 67 "sql_parser.y"
                             {
        (yyval.col) = append_column((yyvsp[-2].col), (yyvsp[0].col));
    }
#line 1310 "y.tab.c"
    break;

  case 6: /* column: IDENTIFIER '.' dotted_identifier  */
#line 73 "sql_parser.y"
                                     {
        (yyval.col) = create_column((yyvsp[-2].strval), (yyvsp[0].strval));
        free((yyvsp[-2].strval));
        free((yyvsp[0].strval));
    }
#line 1320 "y.tab.c"
    break;

  case 7: /* column: IDENTIFIER '.' '*'  */
#line 78 "sql_parser.y"
                         {
        (yyval.col) = create_column((yyvsp[-2].strval), strdup("*"));
        free((yyvsp[-2].strval));
    }
#line 1329 "y.tab.c"
    break;

  case 8: /* dotted_identifier: IDENTIFIER  */
#line 85 "sql_parser.y"
               {
        (yyval.strval) = strdup((yyvsp[0].strval));
        free((yyvsp[0].strval));
    }
#line 1338 "y.tab.c"
    break;

  case 9: /* dotted_identifier: dotted_identifier '.' IDENTIFIER  */
#line 89 "sql_parser.y"
                                       {
        char* temp = (char*)malloc(strlen((yyvsp[-2].strval)) + strlen((yyvsp[0].strval)) + 2); // +2 for the dot and null terminator
        sprintf(temp, "%s.%s", (yyvsp[-2].strval), (yyvsp[0].strval));
        (yyval.strval) = temp;
        free((yyvsp[-2].strval));
        free((yyvsp[0].strval));
    }
#line 1350 "y.tab.c"
    break;

  case 10: /* join_list: table_item  */
#line 99 "sql_parser.y"
               {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1358 "y.tab.c"
    break;

  case 11: /* join_list: join_list ',' table_item  */
#line 102 "sql_parser.y"
                               {
        // Implicit cross join (comma-separated tables)
        // Create a join with no condition (will be added in WHERE clause)
        Condition *cond = create_comparison(COND_EQ, NULL, NULL, 0, 1, 0.0, NULL, NULL, NULL);
        (yyval.node) = create_join_node((yyvsp[-2].node), (yyvsp[0].node), cond);
    }
#line 1369 "y.tab.c"
    break;

  case 12: /* join_list: join_list JOIN join_table ON join_condition  */
#line 108 "sql_parser.y"
                                                  {
        (yyval.node) = create_join_node((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].cond));
    }
#line 1377 "y.tab.c"
    break;

  case 13: /* join_table: table_item  */
#line 114 "sql_parser.y"
               {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1385 "y.tab.c"
    break;

  case 14: /* table_item: table_ref  */
#line 120 "sql_parser.y"
              {
        (yyval.node) = create_base_relation((yyvsp[0].tbl));
    }
#line 1393 "y.tab.c"
    break;

  case 15: /* table_item: subquery  */
#line 123 "sql_parser.y"
               {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1401 "y.tab.c"
    break;

  case 16: /* subquery: '(' query_stmt ')' AS IDENTIFIER  */
#line 129 "sql_parser.y"
                                     {
        (yyval.node) = create_subquery_node((yyvsp[-3].node), (yyvsp[0].strval));
        free((yyvsp[0].strval));
    }
#line 1410 "y.tab.c"
    break;

  case 17: /* subquery: '(' query_stmt ')' IDENTIFIER  */
#line 133 "sql_parser.y"
                                    {  /* Implicit AS for subquery */
        (yyval.node) = create_subquery_node((yyvsp[-2].node), (yyvsp[0].strval));
        free((yyvsp[0].strval));
    }
#line 1419 "y.tab.c"
    break;

  case 18: /* table_ref: IDENTIFIER  */
#line 140 "sql_parser.y"
               {
        (yyval.tbl) = create_table((yyvsp[0].strval), NULL);
        free((yyvsp[0].strval));
    }
#line 1428 "y.tab.c"
    break;

  case 19: /* table_ref: IDENTIFIER AS IDENTIFIER  */
#line 144 "sql_parser.y"
                               {
        (yyval.tbl) = create_table((yyvsp[-2].strval), (yyvsp[0].strval));
        free((yyvsp[-2].strval));
        free((yyvsp[0].strval));
    }
#line 1438 "y.tab.c"
    break;

  case 20: /* table_ref: IDENTIFIER IDENTIFIER  */
#line 149 "sql_parser.y"
                            {  /* Implicit AS */
        (yyval.tbl) = create_table((yyvsp[-1].strval), (yyvsp[0].strval));
        free((yyvsp[-1].strval));
        free((yyvsp[0].strval));
    }
#line 1448 "y.tab.c"
    break;

  case 21: /* opt_where_clause: %empty  */
#line 166 "sql_parser.y"
                {
        (yyval.cond) = NULL;
    }
#line 1456 "y.tab.c"
    break;

  case 22: /* opt_where_clause: where_clause  */
#line 169 "sql_parser.y"
                   {
        (yyval.cond) = (yyvsp[0].cond);
    }
#line 1464 "y.tab.c"
    break;

  case 23: /* where_clause: WHERE condition  */
#line 175 "sql_parser.y"
                    {
        (yyval.cond) = (yyvsp[0].cond);
    }
#line 1472 "y.tab.c"
    break;

  case 24: /* join_condition: condition  */
#line 181 "sql_parser.y"
              {
        (yyval.cond) = (yyvsp[0].cond);
    }
#line 1480 "y.tab.c"
    break;

  case 25: /* condition: comparison_expr  */
#line 187 "sql_parser.y"
                    {
        (yyval.cond) = (yyvsp[0].cond);
    }
#line 1488 "y.tab.c"
    break;

  case 26: /* condition: condition AND condition  */
#line 190 "sql_parser.y"
                              {
        (yyval.cond) = create_binary_condition(COND_AND, (yyvsp[-2].cond), (yyvsp[0].cond));
    }
#line 1496 "y.tab.c"
    break;

  case 27: /* condition: condition OR condition  */
#line 193 "sql_parser.y"
                             {
        (yyval.cond) = create_binary_condition(COND_OR, (yyvsp[-2].cond), (yyvsp[0].cond));
    }
#line 1504 "y.tab.c"
    break;

  case 28: /* condition: NOT condition  */
#line 196 "sql_parser.y"
                    {
        (yyval.cond) = create_unary_condition(COND_NOT, (yyvsp[0].cond));
    }
#line 1512 "y.tab.c"
    break;

  case 29: /* condition: '(' condition ')'  */
#line 199 "sql_parser.y"
                        {
        (yyval.cond) = (yyvsp[-1].cond);
    }
#line 1520 "y.tab.c"
    break;

  case 30: /* comparison_expr: IDENTIFIER '.' dotted_identifier EQ IDENTIFIER '.' dotted_identifier  */
#line 205 "sql_parser.y"
                                                                         {
        (yyval.cond) = create_comparison(COND_EQ, (yyvsp[-6].strval), (yyvsp[-4].strval), 3, 0, 0.0, NULL, (yyvsp[-2].strval), (yyvsp[0].strval));
        free((yyvsp[-6].strval));
        free((yyvsp[-4].strval));
        free((yyvsp[-2].strval));
        free((yyvsp[0].strval));
    }
#line 1532 "y.tab.c"
    break;

  case 31: /* comparison_expr: IDENTIFIER '.' dotted_identifier EQ INT_LITERAL  */
#line 212 "sql_parser.y"
                                                      {
        (yyval.cond) = create_comparison(COND_EQ, (yyvsp[-4].strval), (yyvsp[-2].strval), 0, (yyvsp[0].intval), 0.0, NULL, NULL, NULL);
        free((yyvsp[-4].strval));
        free((yyvsp[-2].strval));
    }
#line 1542 "y.tab.c"
    break;

  case 32: /* comparison_expr: IDENTIFIER '.' dotted_identifier EQ FLOAT_LITERAL  */
#line 217 "sql_parser.y"
                                                        {
        (yyval.cond) = create_comparison(COND_EQ, (yyvsp[-4].strval), (yyvsp[-2].strval), 1, 0, (yyvsp[0].floatval), NULL, NULL, NULL);
        free((yyvsp[-4].strval));
        free((yyvsp[-2].strval));
    }
#line 1552 "y.tab.c"
    break;

  case 33: /* comparison_expr: IDENTIFIER '.' dotted_identifier EQ STRING_LITERAL  */
#line 222 "sql_parser.y"
                                                         {
        (yyval.cond) = create_comparison(COND_EQ, (yyvsp[-4].strval), (yyvsp[-2].strval), 2, 0, 0.0, (yyvsp[0].strval), NULL, NULL);
        free((yyvsp[-4].strval));
        free((yyvsp[-2].strval));
        free((yyvsp[0].strval));
    }
#line 1563 "y.tab.c"
    break;

  case 34: /* comparison_expr: IDENTIFIER '.' dotted_identifier LT IDENTIFIER '.' dotted_identifier  */
#line 228 "sql_parser.y"
                                                                           {
        (yyval.cond) = create_comparison(COND_LT, (yyvsp[-6].strval), (yyvsp[-4].strval), 3, 0, 0.0, NULL, (yyvsp[-2].strval), (yyvsp[0].strval));
        free((yyvsp[-6].strval));
        free((yyvsp[-4].strval));
        free((yyvsp[-2].strval));
        free((yyvsp[0].strval));
    }
#line 1575 "y.tab.c"
    break;

  case 35: /* comparison_expr: IDENTIFIER '.' dotted_identifier GT IDENTIFIER '.' dotted_identifier  */
#line 235 "sql_parser.y"
                                                                           {
        (yyval.cond) = create_comparison(COND_GT, (yyvsp[-6].strval), (yyvsp[-4].strval), 3, 0, 0.0, NULL, (yyvsp[-2].strval), (yyvsp[0].strval));
        free((yyvsp[-6].strval));
        free((yyvsp[-4].strval));
        free((yyvsp[-2].strval));
        free((yyvsp[0].strval));
    }
#line 1587 "y.tab.c"
    break;

  case 36: /* comparison_expr: IDENTIFIER '.' dotted_identifier LE IDENTIFIER '.' dotted_identifier  */
#line 242 "sql_parser.y"
                                                                           {
        (yyval.cond) = create_comparison(COND_LE, (yyvsp[-6].strval), (yyvsp[-4].strval), 3, 0, 0.0, NULL, (yyvsp[-2].strval), (yyvsp[0].strval));
        free((yyvsp[-6].strval));
        free((yyvsp[-4].strval));
        free((yyvsp[-2].strval));
        free((yyvsp[0].strval));
    }
#line 1599 "y.tab.c"
    break;

  case 37: /* comparison_expr: IDENTIFIER '.' dotted_identifier GE IDENTIFIER '.' dotted_identifier  */
#line 249 "sql_parser.y"
                                                                           {
        (yyval.cond) = create_comparison(COND_GE, (yyvsp[-6].strval), (yyvsp[-4].strval), 3, 0, 0.0, NULL, (yyvsp[-2].strval), (yyvsp[0].strval));
        free((yyvsp[-6].strval));
        free((yyvsp[-4].strval));
        free((yyvsp[-2].strval));
        free((yyvsp[0].strval));
    }
#line 1611 "y.tab.c"
    break;

  case 38: /* comparison_expr: IDENTIFIER '.' dotted_identifier NE IDENTIFIER '.' dotted_identifier  */
#line 256 "sql_parser.y"
                                                                           {
        (yyval.cond) = create_comparison(COND_NE, (yyvsp[-6].strval), (yyvsp[-4].strval), 3, 0, 0.0, NULL, (yyvsp[-2].strval), (yyvsp[0].strval));
        free((yyvsp[-6].strval));
        free((yyvsp[-4].strval));
        free((yyvsp[-2].strval));
        free((yyvsp[0].strval));
    }
#line 1623 "y.tab.c"
    break;

  case 39: /* comparison_expr: IDENTIFIER '.' dotted_identifier LT INT_LITERAL  */
#line 263 "sql_parser.y"
                                                      {
        (yyval.cond) = create_comparison(COND_LT, (yyvsp[-4].strval), (yyvsp[-2].strval), 0, (yyvsp[0].intval), 0.0, NULL, NULL, NULL);
        free((yyvsp[-4].strval));
        free((yyvsp[-2].strval));
    }
#line 1633 "y.tab.c"
    break;

  case 40: /* comparison_expr: IDENTIFIER '.' dotted_identifier GT INT_LITERAL  */
#line 268 "sql_parser.y"
                                                      {
        (yyval.cond) = create_comparison(COND_GT, (yyvsp[-4].strval), (yyvsp[-2].strval), 0, (yyvsp[0].intval), 0.0, NULL, NULL, NULL);
        free((yyvsp[-4].strval));
        free((yyvsp[-2].strval));
    }
#line 1643 "y.tab.c"
    break;

  case 41: /* comparison_expr: IDENTIFIER '.' dotted_identifier LE INT_LITERAL  */
#line 273 "sql_parser.y"
                                                      {
        (yyval.cond) = create_comparison(COND_LE, (yyvsp[-4].strval), (yyvsp[-2].strval), 0, (yyvsp[0].intval), 0.0, NULL, NULL, NULL);
        free((yyvsp[-4].strval));
        free((yyvsp[-2].strval));
    }
#line 1653 "y.tab.c"
    break;

  case 42: /* comparison_expr: IDENTIFIER '.' dotted_identifier GE INT_LITERAL  */
#line 278 "sql_parser.y"
                                                      {
        (yyval.cond) = create_comparison(COND_GE, (yyvsp[-4].strval), (yyvsp[-2].strval), 0, (yyvsp[0].intval), 0.0, NULL, NULL, NULL);
        free((yyvsp[-4].strval));
        free((yyvsp[-2].strval));
    }
#line 1663 "y.tab.c"
    break;

  case 43: /* comparison_expr: IDENTIFIER '.' dotted_identifier NE INT_LITERAL  */
#line 283 "sql_parser.y"
                                                      {
        (yyval.cond) = create_comparison(COND_NE, (yyvsp[-4].strval), (yyvsp[-2].strval), 0, (yyvsp[0].intval), 0.0, NULL, NULL, NULL);
        free((yyvsp[-4].strval));
        free((yyvsp[-2].strval));
    }
#line 1673 "y.tab.c"
    break;

  case 44: /* comparison_expr: IDENTIFIER '.' dotted_identifier LT FLOAT_LITERAL  */
#line 288 "sql_parser.y"
                                                        {
        (yyval.cond) = create_comparison(COND_LT, (yyvsp[-4].strval), (yyvsp[-2].strval), 1, 0, (yyvsp[0].floatval), NULL, NULL, NULL);
        free((yyvsp[-4].strval));
        free((yyvsp[-2].strval));
    }
#line 1683 "y.tab.c"
    break;

  case 45: /* comparison_expr: IDENTIFIER '.' dotted_identifier GT FLOAT_LITERAL  */
#line 293 "sql_parser.y"
                                                        {
        (yyval.cond) = create_comparison(COND_GT, (yyvsp[-4].strval), (yyvsp[-2].strval), 1, 0, (yyvsp[0].floatval), NULL, NULL, NULL);
        free((yyvsp[-4].strval));
        free((yyvsp[-2].strval));
    }
#line 1693 "y.tab.c"
    break;

  case 46: /* comparison_expr: IDENTIFIER '.' dotted_identifier LE FLOAT_LITERAL  */
#line 298 "sql_parser.y"
                                                        {
        (yyval.cond) = create_comparison(COND_LE, (yyvsp[-4].strval), (yyvsp[-2].strval), 1, 0, (yyvsp[0].floatval), NULL, NULL, NULL);
        free((yyvsp[-4].strval));
        free((yyvsp[-2].strval));
    }
#line 1703 "y.tab.c"
    break;

  case 47: /* comparison_expr: IDENTIFIER '.' dotted_identifier GE FLOAT_LITERAL  */
#line 303 "sql_parser.y"
                                                        {
        (yyval.cond) = create_comparison(COND_GE, (yyvsp[-4].strval), (yyvsp[-2].strval), 1, 0, (yyvsp[0].floatval), NULL, NULL, NULL);
        free((yyvsp[-4].strval));
        free((yyvsp[-2].strval));
    }
#line 1713 "y.tab.c"
    break;

  case 48: /* comparison_expr: IDENTIFIER '.' dotted_identifier NE FLOAT_LITERAL  */
#line 308 "sql_parser.y"
                                                        {
        (yyval.cond) = create_comparison(COND_NE, (yyvsp[-4].strval), (yyvsp[-2].strval), 1, 0, (yyvsp[0].floatval), NULL, NULL, NULL);
        free((yyvsp[-4].strval));
        free((yyvsp[-2].strval));
    }
#line 1723 "y.tab.c"
    break;

  case 49: /* comparison_expr: IDENTIFIER '.' dotted_identifier '-' INT_LITERAL LT INT_LITERAL  */
#line 314 "sql_parser.y"
                                                                      {
        int combined = (yyvsp[-2].intval) + (yyvsp[0].intval);
        (yyval.cond) = create_comparison(COND_LT, (yyvsp[-6].strval), (yyvsp[-4].strval), 0, combined, 0.0, NULL, NULL, NULL);
        free((yyvsp[-6].strval));
        free((yyvsp[-4].strval));
    }
#line 1734 "y.tab.c"
    break;

  case 50: /* comparison_expr: IDENTIFIER '.' dotted_identifier '-' INT_LITERAL GT INT_LITERAL  */
#line 320 "sql_parser.y"
                                                                      {
        int combined = (yyvsp[-2].intval) + (yyvsp[0].intval);
        (yyval.cond) = create_comparison(COND_GT, (yyvsp[-6].strval), (yyvsp[-4].strval), 0, combined, 0.0, NULL, NULL, NULL);
        free((yyvsp[-6].strval));
        free((yyvsp[-4].strval));
    }
#line 1745 "y.tab.c"
    break;

  case 51: /* comparison_expr: IDENTIFIER '.' dotted_identifier '-' INT_LITERAL LE INT_LITERAL  */
#line 326 "sql_parser.y"
                                                                      {
        int combined = (yyvsp[-2].intval) + (yyvsp[0].intval);
        (yyval.cond) = create_comparison(COND_LE, (yyvsp[-6].strval), (yyvsp[-4].strval), 0, combined, 0.0, NULL, NULL, NULL);
        free((yyvsp[-6].strval));
        free((yyvsp[-4].strval));
    }
#line 1756 "y.tab.c"
    break;

  case 52: /* comparison_expr: IDENTIFIER '.' dotted_identifier '-' INT_LITERAL GE INT_LITERAL  */
#line 332 "sql_parser.y"
                                                                      {
        int combined = (yyvsp[-2].intval) + (yyvsp[0].intval);
        (yyval.cond) = create_comparison(COND_GE, (yyvsp[-6].strval), (yyvsp[-4].strval), 0, combined, 0.0, NULL, NULL, NULL);
        free((yyvsp[-6].strval));
        free((yyvsp[-4].strval));
    }
#line 1767 "y.tab.c"
    break;

  case 53: /* comparison_expr: IDENTIFIER '.' dotted_identifier LT STRING_LITERAL  */
#line 338 "sql_parser.y"
                                                         {
        (yyval.cond) = create_comparison(COND_LT, (yyvsp[-4].strval), (yyvsp[-2].strval), 2, 0, 0.0, (yyvsp[0].strval), NULL, NULL);
        free((yyvsp[-4].strval));
        free((yyvsp[-2].strval));
        free((yyvsp[0].strval));
    }
#line 1778 "y.tab.c"
    break;

  case 54: /* comparison_expr: IDENTIFIER '.' dotted_identifier GT STRING_LITERAL  */
#line 344 "sql_parser.y"
                                                         {
        (yyval.cond) = create_comparison(COND_GT, (yyvsp[-4].strval), (yyvsp[-2].strval), 2, 0, 0.0, (yyvsp[0].strval), NULL, NULL);
        free((yyvsp[-4].strval));
        free((yyvsp[-2].strval));
        free((yyvsp[0].strval));
    }
#line 1789 "y.tab.c"
    break;

  case 55: /* comparison_expr: IDENTIFIER '.' dotted_identifier LE STRING_LITERAL  */
#line 350 "sql_parser.y"
                                                         {
        (yyval.cond) = create_comparison(COND_LE, (yyvsp[-4].strval), (yyvsp[-2].strval), 2, 0, 0.0, (yyvsp[0].strval), NULL, NULL);
        free((yyvsp[-4].strval));
        free((yyvsp[-2].strval));
        free((yyvsp[0].strval));
    }
#line 1800 "y.tab.c"
    break;

  case 56: /* comparison_expr: IDENTIFIER '.' dotted_identifier GE STRING_LITERAL  */
#line 356 "sql_parser.y"
                                                         {
        (yyval.cond) = create_comparison(COND_GE, (yyvsp[-4].strval), (yyvsp[-2].strval), 2, 0, 0.0, (yyvsp[0].strval), NULL, NULL);
        free((yyvsp[-4].strval));
        free((yyvsp[-2].strval));
        free((yyvsp[0].strval));
    }
#line 1811 "y.tab.c"
    break;

  case 57: /* comparison_expr: IDENTIFIER '.' dotted_identifier NE STRING_LITERAL  */
#line 362 "sql_parser.y"
                                                         {
        (yyval.cond) = create_comparison(COND_NE, (yyvsp[-4].strval), (yyvsp[-2].strval), 2, 0, 0.0, (yyvsp[0].strval), NULL, NULL);
        free((yyvsp[-4].strval));
        free((yyvsp[-2].strval));
        free((yyvsp[0].strval));
    }
#line 1822 "y.tab.c"
    break;

  case 58: /* comparison_expr: '(' IDENTIFIER '.' dotted_identifier MULTIPLY INT_LITERAL ')' PLUS INT_LITERAL GT INT_LITERAL  */
#line 370 "sql_parser.y"
                                                                                                    {
        int combined = ((yyvsp[0].intval) - (yyvsp[-2].intval)) / (yyvsp[-5].intval);
        (yyval.cond) = create_comparison(COND_GT, (yyvsp[-9].strval), (yyvsp[-7].strval), 0, combined, 0.0, NULL, NULL, NULL);
        free((yyvsp[-9].strval));
        free((yyvsp[-7].strval));
    }
#line 1833 "y.tab.c"
    break;

  case 59: /* comparison_expr: '(' IDENTIFIER '.' dotted_identifier MULTIPLY INT_LITERAL ')' PLUS INT_LITERAL LT INT_LITERAL  */
#line 376 "sql_parser.y"
                                                                                                    {
        int combined = ((yyvsp[0].intval) - (yyvsp[-2].intval)) / (yyvsp[-5].intval);
        (yyval.cond) = create_comparison(COND_LT, (yyvsp[-9].strval), (yyvsp[-7].strval), 0, combined, 0.0, NULL, NULL, NULL);
        free((yyvsp[-9].strval));
        free((yyvsp[-7].strval));
    }
#line 1844 "y.tab.c"
    break;

  case 60: /* comparison_expr: '(' IDENTIFIER '.' dotted_identifier MULTIPLY INT_LITERAL ')' PLUS INT_LITERAL GE INT_LITERAL  */
#line 382 "sql_parser.y"
                                                                                                    {
        int combined = ((yyvsp[0].intval) - (yyvsp[-2].intval)) / (yyvsp[-5].intval);
        (yyval.cond) = create_comparison(COND_GE, (yyvsp[-9].strval), (yyvsp[-7].strval), 0, combined, 0.0, NULL, NULL, NULL);
        free((yyvsp[-9].strval));
        free((yyvsp[-7].strval));
    }
#line 1855 "y.tab.c"
    break;

  case 61: /* comparison_expr: '(' IDENTIFIER '.' dotted_identifier MULTIPLY INT_LITERAL ')' PLUS INT_LITERAL LE INT_LITERAL  */
#line 388 "sql_parser.y"
                                                                                                    {
        int combined = ((yyvsp[0].intval) - (yyvsp[-2].intval)) / (yyvsp[-5].intval);
        (yyval.cond) = create_comparison(COND_LE, (yyvsp[-9].strval), (yyvsp[-7].strval), 0, combined, 0.0, NULL, NULL, NULL);
        free((yyvsp[-9].strval));
        free((yyvsp[-7].strval));
    }
#line 1866 "y.tab.c"
    break;

  case 62: /* comparison_expr: '(' IDENTIFIER '.' dotted_identifier MULTIPLY INT_LITERAL ')' PLUS INT_LITERAL EQ INT_LITERAL  */
#line 394 "sql_parser.y"
                                                                                                    {
        int combined = ((yyvsp[0].intval) - (yyvsp[-2].intval)) / (yyvsp[-5].intval);
        (yyval.cond) = create_comparison(COND_EQ, (yyvsp[-9].strval), (yyvsp[-7].strval), 0, combined, 0.0, NULL, NULL, NULL);
        free((yyvsp[-9].strval));
        free((yyvsp[-7].strval));
    }
#line 1877 "y.tab.c"
    break;

  case 63: /* comparison_expr: IDENTIFIER '.' dotted_identifier MULTIPLY INT_LITERAL GT INT_LITERAL  */
#line 401 "sql_parser.y"
                                                                           {
        int combined = (yyvsp[-2].intval) * (yyvsp[0].intval);
        (yyval.cond) = create_comparison(COND_GT, (yyvsp[-6].strval), (yyvsp[-4].strval), 0, combined, 0.0, NULL, NULL, NULL);
        free((yyvsp[-6].strval));
        free((yyvsp[-4].strval));
    }
#line 1888 "y.tab.c"
    break;

  case 64: /* comparison_expr: IDENTIFIER '.' dotted_identifier MULTIPLY INT_LITERAL LT INT_LITERAL  */
#line 407 "sql_parser.y"
                                                                           {
        int combined = (yyvsp[-2].intval) * (yyvsp[0].intval);
        (yyval.cond) = create_comparison(COND_LT, (yyvsp[-6].strval), (yyvsp[-4].strval), 0, combined, 0.0, NULL, NULL, NULL);
        free((yyvsp[-6].strval));
        free((yyvsp[-4].strval));
    }
#line 1899 "y.tab.c"
    break;

  case 65: /* comparison_expr: IDENTIFIER '.' dotted_identifier MULTIPLY INT_LITERAL GE INT_LITERAL  */
#line 413 "sql_parser.y"
                                                                           {
        int combined = (yyvsp[-2].intval) * (yyvsp[0].intval);
        (yyval.cond) = create_comparison(COND_GE, (yyvsp[-6].strval), (yyvsp[-4].strval), 0, combined, 0.0, NULL, NULL, NULL);
        free((yyvsp[-6].strval));
        free((yyvsp[-4].strval));
    }
#line 1910 "y.tab.c"
    break;

  case 66: /* comparison_expr: IDENTIFIER '.' dotted_identifier MULTIPLY INT_LITERAL LE INT_LITERAL  */
#line 419 "sql_parser.y"
                                                                           {
        int combined = (yyvsp[-2].intval) * (yyvsp[0].intval);
        (yyval.cond) = create_comparison(COND_LE, (yyvsp[-6].strval), (yyvsp[-4].strval), 0, combined, 0.0, NULL, NULL, NULL);
        free((yyvsp[-6].strval));
        free((yyvsp[-4].strval));
    }
#line 1921 "y.tab.c"
    break;

  case 67: /* comparison_expr: IDENTIFIER '.' dotted_identifier MULTIPLY INT_LITERAL EQ INT_LITERAL  */
#line 425 "sql_parser.y"
                                                                           {
        int combined = (yyvsp[-2].intval) * (yyvsp[0].intval);
        (yyval.cond) = create_comparison(COND_EQ, (yyvsp[-6].strval), (yyvsp[-4].strval), 0, combined, 0.0, NULL, NULL, NULL);
        free((yyvsp[-6].strval));
        free((yyvsp[-4].strval));
    }
#line 1932 "y.tab.c"
    break;

  case 68: /* comparison_expr: IDENTIFIER '.' dotted_identifier PLUS INT_LITERAL GT INT_LITERAL  */
#line 432 "sql_parser.y"
                                                                       {
        int combined = (yyvsp[-2].intval) + (yyvsp[0].intval);
        (yyval.cond) = create_comparison(COND_GT, (yyvsp[-6].strval), (yyvsp[-4].strval), 0, combined, 0.0, NULL, NULL, NULL);
        free((yyvsp[-6].strval));
        free((yyvsp[-4].strval));
    }
#line 1943 "y.tab.c"
    break;

  case 69: /* comparison_expr: IDENTIFIER '.' dotted_identifier PLUS INT_LITERAL LT INT_LITERAL  */
#line 438 "sql_parser.y"
                                                                       {
        int combined = (yyvsp[-2].intval) + (yyvsp[0].intval);
        (yyval.cond) = create_comparison(COND_LT, (yyvsp[-6].strval), (yyvsp[-4].strval), 0, combined, 0.0, NULL, NULL, NULL);
        free((yyvsp[-6].strval));
        free((yyvsp[-4].strval));
    }
#line 1954 "y.tab.c"
    break;

  case 70: /* comparison_expr: IDENTIFIER '.' dotted_identifier PLUS INT_LITERAL GE INT_LITERAL  */
#line 444 "sql_parser.y"
                                                                       {
        int combined = (yyvsp[-2].intval) + (yyvsp[0].intval);
        (yyval.cond) = create_comparison(COND_GE, (yyvsp[-6].strval), (yyvsp[-4].strval), 0, combined, 0.0, NULL, NULL, NULL);
        free((yyvsp[-6].strval));
        free((yyvsp[-4].strval));
    }
#line 1965 "y.tab.c"
    break;

  case 71: /* comparison_expr: IDENTIFIER '.' dotted_identifier PLUS INT_LITERAL LE INT_LITERAL  */
#line 450 "sql_parser.y"
                                                                       {
        int combined = (yyvsp[-2].intval) + (yyvsp[0].intval);
        (yyval.cond) = create_comparison(COND_LE, (yyvsp[-6].strval), (yyvsp[-4].strval), 0, combined, 0.0, NULL, NULL, NULL);
        free((yyvsp[-6].strval));
        free((yyvsp[-4].strval));
    }
#line 1976 "y.tab.c"
    break;

  case 72: /* comparison_expr: IDENTIFIER '.' dotted_identifier PLUS INT_LITERAL EQ INT_LITERAL  */
#line 456 "sql_parser.y"
                                                                       {
        int combined = (yyvsp[-2].intval) + (yyvsp[0].intval);
        (yyval.cond) = create_comparison(COND_EQ, (yyvsp[-6].strval), (yyvsp[-4].strval), 0, combined, 0.0, NULL, NULL, NULL);
        free((yyvsp[-6].strval));
        free((yyvsp[-4].strval));
    }
#line 1987 "y.tab.c"
    break;


#line 1991 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 464 "sql_parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

/* Helper functions for handling dotted attribute names */
char* get_first_part(const char* dotted_str) {
    // Returns the part before the first dot
    char* dot_pos = strchr(dotted_str, '.');
    if (dot_pos == NULL) {
        return strdup(dotted_str); // No dot found, return the whole string
    }
    
    int length = dot_pos - dotted_str;
    char* result = (char*)malloc(length + 1);
    strncpy(result, dotted_str, length);
    result[length] = '\0';
    return result;
}

char* get_remaining_part(const char* dotted_str) {
    // Returns everything after the first dot
    char* dot_pos = strchr(dotted_str, '.');
    if (dot_pos == NULL) {
        return NULL; // No dot found
    }
    
    return strdup(dot_pos + 1); // +1 to skip the dot itself
}

Column *create_column(char *table, char *attr) {
    Column *col = (Column *)malloc(sizeof(Column));
    col->table = strdup(table);
    col->attr = strdup(attr);
    col->next = NULL;
    return col;
}

Column *append_column(Column *list, Column *new_col) {
    if (list == NULL) {
        return new_col;
    }
    
    Column *current = list;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_col;
    return list;
}

Table *create_table(char *name, char *alias) {
    Table *tbl = (Table *)malloc(sizeof(Table));
    tbl->name = strdup(name);
    tbl->alias = (alias != NULL) ? strdup(alias) : NULL;
    tbl->next = NULL;
    return tbl;
}

Table *append_table(Table *list, Table *new_table) {
    if (list == NULL) {
        return new_table;
    }
    
    Table *current = list;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_table;
    return list;
}

Condition *create_comparison(CondType type, char *table, char *attr, int literal_type, 
                            int int_val, float float_val, char *str_val, 
                            char *cmp_table, char *cmp_attr) {
    Condition *cond = (Condition *)malloc(sizeof(Condition));
    cond->type = type;
    cond->expr.comparison.table = strdup(table);
    cond->expr.comparison.attr = strdup(attr);
    cond->expr.comparison.literal_type = literal_type;
    
    if (literal_type == 0) { /* int */
        cond->expr.comparison.int_literal = int_val;
    } else if (literal_type == 1) { /* float */
        cond->expr.comparison.float_literal = float_val;
    } else if (literal_type == 2) { /* string */
        cond->expr.comparison.str_literal = strdup(str_val);
    } else if (literal_type == 3) { /* column */
        cond->expr.comparison.cmp_table = strdup(cmp_table);
        cond->expr.comparison.cmp_attr = strdup(cmp_attr);
    }
    
    return cond;
}

Condition *create_binary_condition(CondType type, Condition *left, Condition *right) {
    Condition *cond = (Condition *)malloc(sizeof(Condition));
    cond->type = type;
    cond->expr.binary.left = left;
    cond->expr.binary.right = right;
    return cond;
}

Condition *create_unary_condition(CondType type, Condition *cond_expr) {
    Condition *cond = (Condition *)malloc(sizeof(Condition));
    cond->type = type;
    cond->expr.unary.cond = cond_expr;
    return cond;
}

RelNode *create_project_node(RelNode *input, Column *columns) {
    RelNode *node = (RelNode *)malloc(sizeof(RelNode));
    node->op_type = OP_PROJECT;
    node->op.project.input = input;
    node->op.project.columns = columns;
    node->tables = NULL;
    return node;
}

RelNode *create_select_node(RelNode *input, Condition *condition) {
    RelNode *node = (RelNode *)malloc(sizeof(RelNode));
    node->op_type = OP_SELECT;
    node->op.select.input = input;
    node->op.select.condition = condition;
    node->tables = NULL;
    return node;
}

RelNode *create_join_node(RelNode *left, RelNode *right, Condition *condition) {
    RelNode *node = (RelNode *)malloc(sizeof(RelNode));
    node->op_type = OP_JOIN;
    node->op.join.left = left;
    node->op.join.right = right;
    node->op.join.condition = condition;
    node->tables = NULL;
    return node;
}

RelNode *create_rename_node(RelNode *input, char *old_name, char *new_name) {
    RelNode *node = (RelNode *)malloc(sizeof(RelNode));
    node->op_type = OP_RENAME;
    node->op.rename.input = input;
    node->op.rename.old_name = strdup(old_name);
    node->op.rename.new_name = strdup(new_name);
    node->tables = NULL;
    return node;
}

RelNode *create_base_relation(Table *tables) {
    RelNode *node = (RelNode *)malloc(sizeof(RelNode));
    node->op_type = (RelOpType)-1; /* Mark as base relation */
    node->tables = tables;
    return node;
}

/* New function to create a subquery node */
RelNode *create_subquery_node(RelNode *subquery, char *alias) {
    RelNode *node = (RelNode *)malloc(sizeof(RelNode));
    node->op_type = OP_SUBQUERY;
    node->op.subquery.subquery = subquery;
    node->op.subquery.alias = strdup(alias);
    node->tables = NULL;
    return node;
}

void print_column_json(Column *col) {
    printf("[");
    while (col != NULL) {
        printf("{\"table\": \"%s\", \"attr\": \"%s\"}", 
               col->table, col->attr);
        col = col->next;
        if (col != NULL) {
            printf(", ");
        }
    }
    printf("]");
}

void print_table_json(Table *tbl) {
    printf("[");
    while (tbl != NULL) {
        printf("{\"name\": \"%s\"", tbl->name);
        if (tbl->alias != NULL) {
            printf(", \"alias\": \"%s\"", tbl->alias);
        }
        printf("}");
        tbl = tbl->next;
        if (tbl != NULL) {
            printf(", ");
        }
    }
    printf("]");
}

void print_condition_json(Condition *cond) {
    if (cond == NULL) {
        printf("null");
        return;
    }
    
    printf("{\"type\": ");
    
    switch (cond->type) {
        case COND_EQ:
            printf("\"EQ\"");
            break;
        case COND_LT:
            printf("\"LT\"");
            break;
        case COND_GT:
            printf("\"GT\"");
            break;
        case COND_LE:
            printf("\"LE\"");
            break;
        case COND_GE:
            printf("\"GE\"");
            break;
        case COND_NE:
            printf("\"NE\"");
            break;
        case COND_AND:
            printf("\"AND\", \"left\": ");
            print_condition_json(cond->expr.binary.left);
            printf(", \"right\": ");
            print_condition_json(cond->expr.binary.right);
            break;
        case COND_OR:
            printf("\"OR\", \"left\": ");
            print_condition_json(cond->expr.binary.left);
            printf(", \"right\": ");
            print_condition_json(cond->expr.binary.right);
            break;
        case COND_NOT:
            printf("\"NOT\", \"cond\": ");
            print_condition_json(cond->expr.unary.cond);
            break;
    }
    
    if (cond->type <= COND_NE) { /* Comparison operation */
        printf(", \"left\": {\"table\": \"%s\", \"attr\": \"%s\"}", 
               cond->expr.comparison.table, cond->expr.comparison.attr);
        
        printf(", \"right\": ");
        
        if (cond->expr.comparison.literal_type == 0) { /* int */
            printf("{\"type\": \"int\", \"value\": %d}", 
                   cond->expr.comparison.int_literal);
        } else if (cond->expr.comparison.literal_type == 1) { /* float */
            printf("{\"type\": \"float\", \"value\": %f}", 
                   cond->expr.comparison.float_literal);
        } else if (cond->expr.comparison.literal_type == 2) { /* string */
            printf("{\"type\": \"string\", \"value\": \"%s\"}", 
                   cond->expr.comparison.str_literal);
        } else if (cond->expr.comparison.literal_type == 3) { /* column */
            printf("{\"type\": \"column\", \"table\": \"%s\", \"attr\": \"%s\"}", 
                   cond->expr.comparison.cmp_table, cond->expr.comparison.cmp_attr);
        }
    }
    
    printf("}");
}

void print_ra_tree_json_rec(RelNode *node) {
    if (node == NULL) {
        printf("null");
        return;
    }
    
    printf("{");
    
    if (node->tables != NULL) { /* Base relation */
        printf("\"type\": \"base_relation\", \"tables\": ");
        print_table_json(node->tables);
    } else {
        switch (node->op_type) {
            case OP_PROJECT:
                printf("\"type\": \"project\", \"columns\": ");
                print_column_json(node->op.project.columns);
                printf(", \"input\": ");
                print_ra_tree_json_rec(node->op.project.input);
                break;
                
            case OP_SELECT:
                printf("\"type\": \"select\", \"condition\": ");
                print_condition_json(node->op.select.condition);
                printf(", \"input\": ");
                print_ra_tree_json_rec(node->op.select.input);
                break;
                
            case OP_JOIN:
                printf("\"type\": \"join\", \"condition\": ");
                print_condition_json(node->op.join.condition);
                printf(", \"left\": ");
                print_ra_tree_json_rec(node->op.join.left);
                printf(", \"right\": ");
                print_ra_tree_json_rec(node->op.join.right);
                break;
                
            case OP_RENAME:
                printf("\"type\": \"rename\", \"old_name\": \"%s\", \"new_name\": \"%s\", \"input\": ", 
                       node->op.rename.old_name, node->op.rename.new_name);
                print_ra_tree_json_rec(node->op.rename.input);
                break;
                
            case OP_SUBQUERY:
                printf("\"type\": \"subquery\", \"alias\": \"%s\", \"query\": ", 
                       node->op.subquery.alias);
                print_ra_tree_json_rec(node->op.subquery.subquery);
                break;
        }
    }
    
    printf("}");
}

void print_ra_tree_json(RelNode *root) {
    print_ra_tree_json_rec(root);
    printf("\n");
}

void free_columns(Column *cols) {
    while (cols != NULL) {
        Column *next = cols->next;
        free(cols->table);
        free(cols->attr);
        free(cols);
        cols = next;
    }
}

void free_tables(Table *tables) {
    while (tables != NULL) {
        Table *next = tables->next;
        free(tables->name);
        if (tables->alias != NULL) {
            free(tables->alias);
        }
        free(tables);
        tables = next;
    }
}

void free_condition(Condition *cond) {
    if (cond == NULL) {
        return;
    }
    
    switch (cond->type) {
        case COND_AND:
        case COND_OR:
            free_condition(cond->expr.binary.left);
            free_condition(cond->expr.binary.right);
            break;
        case COND_NOT:
            free_condition(cond->expr.unary.cond);
            break;
        default: /* Comparison operations */
            free(cond->expr.comparison.table);
            free(cond->expr.comparison.attr);
            
            if (cond->expr.comparison.literal_type == 2) { /* string */
                free(cond->expr.comparison.str_literal);
            } else if (cond->expr.comparison.literal_type == 3) { /* column */
                free(cond->expr.comparison.cmp_table);
                free(cond->expr.comparison.cmp_attr);
            }
            break;
    }
    
    free(cond);
}

void free_relnode(RelNode *node) {
    if (node == NULL) {
        return;
    }
    
    if (node->tables != NULL) { /* Base relation */
        free_tables(node->tables);
    } else {
        switch (node->op_type) {
            case OP_PROJECT:
                free_columns(node->op.project.columns);
                free_relnode(node->op.project.input);
                break;
                
            case OP_SELECT:
                free_condition(node->op.select.condition);
                free_relnode(node->op.select.input);
                break;
                
            case OP_JOIN:
                free_condition(node->op.join.condition);
                free_relnode(node->op.join.left);
                free_relnode(node->op.join.right);
                break;
                
            case OP_RENAME:
                free(node->op.rename.old_name);
                free(node->op.rename.new_name);
                free_relnode(node->op.rename.input);
                break;
                
            case OP_SUBQUERY:
                free(node->op.subquery.alias);
                free_relnode(node->op.subquery.subquery);
                break;
        }
    }
    
    free(node);
}
