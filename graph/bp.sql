-- bonus point lab work


-- TASK 1

SELECT 
    s.full_name AS student_name,
    s.email,
    c.title AS course_name,
    c.category,
    e.enrolled_at
FROM students s
JOIN enrollments e ON s.student_id = e.student_id
JOIN courses c ON e.course_id = c.course_id
WHERE s.status = 'active' AND c.is_active = TRUE;


-- taskl 2

SELECT 
    c.course_id,
    c.title,
    COUNT(e.student_id) AS number_of_students,
    ROUND(AVG(e.final_grade), 2) AS avg_grade
FROM courses c
JOIN enrollments e ON c.course_id = e.course_id
WHERE e.status = 'completed'
GROUP BY c.course_id, c.title
ORDER BY c.course_id;



-- task 3

SELECT 
    s.full_name AS student_name,
    c.title AS course_title,
    p.amount AS payment_amount,
    p.paid_at AS payment_date,
    i.full_name AS instructor_name
FROM payments p
JOIN students s ON p.student_id = s.student_id
JOIN courses c ON p.course_id = c.course_id
JOIN instructors i ON c.instructor_id = i.instructor_id
ORDER BY p.paid_at DESC;




-- Task 4


CREATE OR REPLACE VIEW active_course_enrollments AS
SELECT 
    s.student_id,
    s.full_name AS student_name,
    c.course_id,
    c.title AS course_title,
    e.enrolled_at,
    e.status
FROM enrollments e
JOIN students s ON e.student_id = s.student_id
JOIN courses c ON e.course_id = c.course_id
WHERE s.status <> 'active' AND c.is_active = TRUE;



-- query

SELECT * FROM active_course_enrollments;



-- Task 5



CREATE OR REPLACE VIEW only_active_students AS
SELECT * 
FROM students 
WHERE status = 'active'
WITH LOCAL CHECK OPTION;


INSERT INTO only_active_students (full_name, email, enrollment_year, status)
VALUES ('alibek', 'ailibek@gmail.com', 2024, 'active');

SELECT * FROM students WHERE email = 'ailibek@gmail.com'; -- status is active



-- task 6

CREATE INDEX idx_students_email ON students(email);

SELECT * FROM students WHERE email = 'batman@example.com';



-- task 7

CREATE OR REPLACE FUNCTION get_student_total_paid(p_student_id int) 
RETURNS numeric AS $$
DECLARE
    v_total numeric;
BEGIN
    SELECT COALESCE(SUM(amount), 0) 
    INTO v_total
    FROM payments 
    WHERE student_id = p_student_id;
    
    RETURN v_total;
END;
$$ LANGUAGE plpgsql;



-- example call function

SELECT full_name, get_student_total_paid(student_id) AS total_paid
FROM students
WHERE student_id = 1;


-- task 8

CREATE OR REPLACE FUNCTION get_student_stats(
    p_student_id int, 
    OUT total_paid numeric, 
    OUT course_count int
) 
AS $$
BEGIN
    SELECT 
        COALESCE(SUM(amount), 0), 
        COUNT(DISTINCT course_id)
    INTO total_paid, course_count
    FROM payments
    WHERE student_id = p_student_id;
END;
$$ LANGUAGE plpgsql;


SELECT * FROM get_student_stats(4);


-- task 9

CREATE OR REPLACE FUNCTION apply_discount(INOUT price numeric) 
AS $$
BEGIN
    price := price * 0.90; -- Reduces price by 10%
END;
$$ LANGUAGE plpgsql;


SELECT course_id, title, price AS price_before 
FROM courses 
WHERE category = 'Databases';

-- Update statement using the function
UPDATE courses
SET price = apply_discount(price)
WHERE category = 'Databases';


SELECT course_id, title, price AS price_after 
FROM courses 
WHERE category = 'Databases';




-- TaSK 10

CREATE ROLE los_pollos_hermanos NOLOGIN;

-- Grant permissions
GRANT SELECT ON courses TO los_pollos_hermanos;
GRANT SELECT ON instructors TO los_pollos_hermanos;
GRANT SELECT ON payments TO los_pollos_hermanos;

-- Create users and add to group
CREATE ROLE hacker1 WITH LOGIN PASSWORD 'wokd_1@93kcdcnertvbfkjenc';
CREATE ROLE hacker2 WITH LOGIN PASSWORD 'nvejrPlkjngr9uy3498as0';

GRANT los_pollos_hermanos TO hacker1;
GRANT los_pollos_hermanos TO hacker2;


-- start
SET ROLE hacker1;



SELECT 
    i.full_name AS instructor, 
    SUM(p.amount) AS total_revenue
FROM instructors i
JOIN courses c ON i.instructor_id = c.instructor_id
JOIN payments p ON c.course_id = p.course_id
GROUP BY i.full_name
ORDER BY total_revenue DESC;


RESET ROLE;






