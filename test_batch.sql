SELECT instructor.name, instructor.salary FROM instructor WHERE instructor.salary > 75000

SELECT student.name, course.title FROM student JOIN takes ON student.ID = takes.ID JOIN course ON takes.course_id = course.course_id WHERE course.dept_name = 'Comp. Sci.'

SELECT student.name, takes.course_id FROM student, takes WHERE student.ID = takes.ID AND student.tot_cred > 120

SELECT department.dept_name FROM department WHERE department.budget > 50000

SELECT instructor.name, department.dept_name FROM instructor JOIN department ON instructor.dept_name = department.dept_name WHERE instructor.salary > 80000