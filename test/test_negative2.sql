SELECT student.name, course.title, takes.grade FROM student JOIN takes ON student.ID = takes.ID JOIN course ON takes.course_id = course.course_id WHERE student.tot_cred > 100 AND course.credits = 4
