-- Query 1: Two-table join with filter
SELECT employees.id, departments.id
FROM employees JOIN departments ON employees.dept_id = departments.id
WHERE employees.salary > 50000;

-- Query 2: Three-table join
SELECT employees.id, projects.id
FROM employees
JOIN assignments ON employees.id = assignments.emp_id
JOIN projects ON assignments.project_id = projects.id
WHERE projects.status = 'active' AND employees.age > 30;

-- Query 3: Department + projects
SELECT departments.id, projects.id
FROM departments JOIN projects ON departments.id = projects.dept_id
WHERE departments.location = 'east';
