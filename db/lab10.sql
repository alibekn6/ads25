-- Task 1

CREATE OR REPLACE FUNCTION get_customer_full_name(p_customer_id integer)
RETURNS text
LANGUAGE plpgsql
AS $$
DECLARE
    v_first_name text;
    v_last_name text;
BEGIN
    SELECT first_name, last_name
    INTO v_first_name, v_last_name
    FROM customers
    WHERE customer_id = p_customer_id;
    
    IF NOT FOUND THEN
        RETURN NULL;
    END IF;
    
    RETURN v_last_name || ' ' || v_first_name;
END;
$$;

SELECT get_customer_full_name(1);
SELECT get_customer_full_name(999);


-- Task 2

CREATE OR REPLACE FUNCTION get_rental_duration(p_customer_id integer)
RETURNS integer
LANGUAGE plpgsql
AS $$
DECLARE
    v_total_days integer;
BEGIN
    SELECT COALESCE(SUM(return_date - rental_date), 0)
    INTO v_total_days
    FROM rentals
    WHERE customer_id = p_customer_id
      AND return_date IS NOT NULL;
    
    RETURN v_total_days;
END;
$$;

SELECT get_rental_duration(1);
SELECT get_rental_duration(2);


-- Task 3

CREATE OR REPLACE FUNCTION get_rental_duration(p_customer_id integer, p_from_date date)
RETURNS integer
LANGUAGE plpgsql
AS $$
DECLARE
    v_total_days integer;
BEGIN
    SELECT COALESCE(SUM(return_date - rental_date), 0)
    INTO v_total_days
    FROM rentals
    WHERE customer_id = p_customer_id
      AND return_date IS NOT NULL
      AND rental_date >= p_from_date;
    
    RETURN v_total_days;
END;
$$;

SELECT get_rental_duration(1);
SELECT get_rental_duration(1, '2023-08-01');


-- Task 4

CREATE OR REPLACE FUNCTION get_rental_hi_lo(
    p_customer_id integer,
    OUT max_days integer,
    OUT min_days integer
)
LANGUAGE plpgsql
AS $$
BEGIN
    SELECT 
        MAX(return_date - rental_date),
        MIN(return_date - rental_date)
    INTO max_days, min_days
    FROM rentals
    WHERE customer_id = p_customer_id
      AND return_date IS NOT NULL;
END;
$$;

SELECT * FROM get_rental_hi_lo(1);


-- Task 5

CREATE OR REPLACE FUNCTION apply_discount(
    INOUT p_rate numeric,
    p_discount_percent numeric
)
LANGUAGE plpgsql
AS $$
BEGIN
    p_rate := p_rate - (p_rate * p_discount_percent / 100);
END;
$$;

SELECT apply_discount(30, 10);
SELECT apply_discount(10, 25);


-- Task 6

CREATE OR REPLACE FUNCTION sum_and_avg(
    VARIADIC p_values numeric[],
    OUT total numeric,
    OUT avg_value numeric
)
LANGUAGE plpgsql
AS $$
DECLARE
    v_count integer;
BEGIN
    v_count := array_length(p_values, 1);
    
    IF v_count IS NULL OR v_count = 0 THEN
        total := NULL;
        avg_value := NULL;
        RETURN;
    END IF;
    
    SELECT SUM(val) INTO total
    FROM unnest(p_values) AS val;
    
    avg_value := total / v_count;
END;
$$;

SELECT * FROM sum_and_avg(1, 2, 3);
SELECT * FROM sum_and_avg(10.5, 20.5, 30.0, 40.0);


-- Task 7

CREATE OR REPLACE FUNCTION get_films_by_pattern(p_pattern varchar)
RETURNS TABLE(
    film_id int,
    film_title varchar,
    film_year int,
    film_rating text
)
LANGUAGE plpgsql
AS $$
BEGIN
    RETURN QUERY
    SELECT 
        f.film_id,
        f.title::varchar,
        f.release_year,
        f.rating
    FROM films f
    WHERE f.title LIKE p_pattern;
END;
$$;

SELECT * FROM get_films_by_pattern('A%');
SELECT * FROM get_films_by_pattern('%land%');


-- task 8

CREATE OR REPLACE FUNCTION get_customer_rentals(p_customer_id integer)
RETURNS TABLE(
    rental_id int,
    film_title text,
    rental_date date,
    return_date date,
    rental_days int
)
LANGUAGE plpgsql
AS $$
BEGIN
    RETURN QUERY
    SELECT 
        r.rental_id,
        f.title,
        r.rental_date,
        r.return_date,
        CASE 
            WHEN r.return_date IS NULL THEN NULL
            ELSE (r.return_date - r.rental_date)
        END AS rental_days
    FROM rentals r
    JOIN films f ON r.film_id = f.film_id
    WHERE r.customer_id = p_customer_id;
END;
$$;

SELECT * FROM get_customer_rentals(1);


-- Task 9

CREATE OR REPLACE FUNCTION get_customer_stats(p_customer_id integer)
RETURNS text
LANGUAGE plpgsql
AS $$
DECLARE
    v_rental_count integer;
    v_total_days integer;
    v_result text;
BEGIN
    v_rental_count := 0;
    v_total_days := 0;
    
    BEGIN
        DECLARE
            v_temp_count integer;
            v_temp_days integer;
        BEGIN
            SELECT 
                COUNT(*),
                COALESCE(SUM(return_date - rental_date), 0)
            INTO v_temp_count, v_temp_days
            FROM rentals
            WHERE customer_id = p_customer_id
              AND return_date IS NOT NULL;
            
            v_rental_count := v_temp_count;
            v_total_days := v_temp_days;
        END;
    END;
    
    v_result := 'Customer ' || p_customer_id || ': rentals = ' || 
                v_rental_count || ', total days = ' || v_total_days;
    
    RETURN v_result;
END;
$$;

SELECT get_customer_stats(1);


-- Task 10

CREATE OR REPLACE FUNCTION get_customer_rentals_count(
    p_customer_id integer,
    p_only_returned boolean DEFAULT true
)
RETURNS integer
LANGUAGE plpgsql
AS $$
DECLARE
    v_count integer;
BEGIN
    IF p_only_returned THEN
        SELECT COUNT(*)
        INTO v_count
        FROM rentals
        WHERE customer_id = p_customer_id
          AND return_date IS NOT NULL;
    ELSE
        SELECT COUNT(*)
        INTO v_count
        FROM rentals
        WHERE customer_id = p_customer_id;
    END IF;
    
    RETURN COALESCE(v_count, 0);
END;
$$;

SELECT get_customer_rentals_count(1);
SELECT get_customer_rentals_count(1, false);