SELECT student.name, takes.course_id FROM student, takes WHERE student.ID = takes.ID AND student.tot_cred > 120

SELECT sub.name, sub.title FROM (SELECT student.name, course.title, course.credits FROM student JOIN takes ON student.ID = takes.ID JOIN course ON takes.course_id = course.course_id) AS sub WHERE sub.credits > 3

SELECT student.name, takes.course_id FROM student, takes WHERE student.ID = takes.ID AND student.tot_cred > 120


