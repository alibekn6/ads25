-- Lab Work #6


-- Task 1
CREATE TABLE students (
    id INTEGER NOT NULL,
    full_name TEXT NOT NULL,
    enrolled_at DATE DEFAULT CURRENT_DATE,
    email TEXT
);

INSERT INTO students (id, full_name, enrolled_at, email)
VALUES (1, 'AlibekANAurr', '2025-11-11', 'alibeks@gmail.com');


INSERT INTO students (id, full_name, email)
VALUES (2, 'Abylai Darn', 'darn@kbtu.com');


INSERT INTO students (id, email)
VALUES (3, 'another.email@example.com');


-- Task 2

CREATE TABLE courses (
    course_id INTEGER PRIMARY KEY,
    course_name TEXT NOT NULL
);

INSERT INTO courses (course_id, course_name)
VALUES (101, 'Introduction to ML');

-- fail
INSERT INTO courses (course_id, course_name)
VALUES (101, 'Machine Learning');



-- Task 3


CREATE TABLE passengers (
    passenger_id SERIAL PRIMARY KEY,
    email TEXT UNIQUE
);


INSERT INTO passengers (email)
VALUES ('test@mail.com');

-- fail
INSERT INTO passengers (email)
VALUES ('test@mail.com');


INSERT INTO passengers (email)
VALUES (NULL);

INSERT INTO passengers (email)
VALUES (NULL);



-- Task 4

CREATE TABLE employees (
    emp_id SERIAL PRIMARY KEY,
    age INTEGER CHECK (age >= 18),
    salary NUMERIC(10, 2) CHECK (salary > 0)
);



-- fail
INSERT INTO employees (age, salary)
VALUES (16, 6000.00);


-- fail
INSERT INTO employees (age, salary)
VALUES (25, 0);

-- valid one
INSERT INTO employees (age, salary)
VALUES (30, 5000.00);


-- Task 5

CREATE TABLE products (
    product_id SERIAL PRIMARY KEY,
    regular_price NUMERIC(10, 2) NOT NULL,
    discount_price NUMERIC(10, 2) NOT NULL,
    CONSTRAINT price_check CHECK (discount_price < regular_price)
);

-- fail
INSERT INTO products (regular_price, discount_price)
VALUES (100, 150);

-- valid
INSERT INTO products (regular_price, discount_price)
VALUES (100, 80);


-- Task 6. customers and orders

CREATE TABLE customers (
    customer_id SERIAL PRIMARY KEY,
    full_name TEXT NOT NULL
);

CREATE TABLE orders (
    order_id SERIAL PRIMARY KEY,
    customer_id INTEGER NOT NULL,
    order_total NUMERIC(10, 2) CHECK (order_total > 0),
    FOREIGN KEY (customer_id) REFERENCES customers(customer_id)
);

-- fail due to customer id does not
INSERT INTO orders (customer_id, order_total)
VALUES (999, 150.75);


INSERT INTO customers (full_name)
VALUES ('DARN');

INSERT INTO orders (customer_id, order_total)
VALUES (1, 150.75);


-- Task 7. tickets table

CREATE TABLE tickets (
    ticket_id SERIAL PRIMARY KEY,
    price NUMERIC(10, 2),
    CONSTRAINT positive_price CHECK (price > 0)
);


INSERT INTO tickets (price)
VALUES (-5);

ALTER TABLE tickets
DROP CONSTRAINT positive_price;

-- fail
INSERT INTO tickets (price)
VALUES (-5);


-- Task 8.
CREATE TABLE accounts (
    account_id SERIAL PRIMARY KEY,
    balance    NUMERIC(12,2),
    email      TEXT
);

ALTER TABLE accounts
ADD CONSTRAINT check_balance_non_negative CHECK (balance >= 0);


ALTER TABLE accounts
ADD CONSTRAINT unique_email UNIQUE (email);

INSERT INTO accounts (balance, email) VALUES (1000.00, 'anuarbek@email.com');


-- fail
INSERT INTO accounts (balance, email) VALUES (2000.00, 'anuarbek@email.com');

-- fail
INSERT INTO accounts (balance, email) VALUES (-500.00, 'negative@balance.com');



-- Task 9. drivers table

CREATE TABLE drivers (
    driver_id SERIAL PRIMARY KEY,
    license_number TEXT NOT NULL,
    phone_number TEXT
);


-- fail
INSERT INTO drivers (phone_number)
VALUES ('123-456-7890');


INSERT INTO drivers (license_number)
VALUES ('XYZ123');


-- Task 10. user_profiles table

CREATE TABLE user_profiles (
    user_id SERIAL PRIMARY KEY,
    email TEXT NOT NULL,
    first_name TEXT NOT NULL,
    CONSTRAINT email_format_check CHECK (position('@' in email) > 1)
);

INSERT INTO user_profiles (email, first_name)
VALUES ('alibek@gmail.com', 'alibei');



-- fail
INSERT INTO user_profiles (email, first_name)
VALUES ('not_an_email', 'mad');
