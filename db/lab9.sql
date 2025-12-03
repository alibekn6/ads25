-- Lab Work #9

-- Task 1
CREATE VIEW v_active_customers AS
SELECT id, full_name, city, is_vip
FROM customers
WHERE is_vip = TRUE;

SELECT * FROM v_active_customers;
SELECT * FROM customers;


-- Task 2
CREATE VIEW v_order_lines AS
SELECT 
    o.id AS order_id,
    o.order_date,
    c.full_name AS customer_name,
    p.name AS product_name,
    p.category,
    (oi.quantity * oi.unit_price) AS total_per_row
FROM orders o
JOIN customers c ON o.customer_id = c.id
JOIN order_items oi ON o.id = oi.order_id
JOIN products p ON oi.product_id = p.id;

SELECT * FROM v_order_lines;


-- Task 3
CREATE VIEW v_almaty_customers AS
SELECT id, full_name, city, is_vip
FROM customers
WHERE city = 'Almaty';

-- a) INSERT
INSERT INTO v_almaty_customers (full_name, city, is_vip) 
VALUES ('Nurlan Serik', 'Almaty', FALSE);

SELECT * FROM v_almaty_customers;
SELECT * FROM customers;

-- b) UPDATE
UPDATE v_almaty_customers 
SET city = 'Almaty-2' 
WHERE full_name = 'Alice Akhmetova';

SELECT * FROM v_almaty_customers;
SELECT * FROM customers;


-- Task 4: CHECK OPTION demo
-- a) Base view
CREATE VIEW v_paid_orders AS
SELECT id, customer_id, order_date, status
FROM orders
WHERE status = 'paid';

-- b) View with LOCAL CHECK OPTION
CREATE VIEW v_recent_paid_orders AS
SELECT id, customer_id, order_date, status
FROM v_paid_orders
WHERE order_date >= '2025-01-10'
WITH LOCAL CHECK OPTION;

-- Try INSERT with valid date but invalid status (passes with LOCAL)
INSERT INTO v_recent_paid_orders (customer_id, order_date, status) 
VALUES (1, '2025-01-15', 'new');

-- Try INSERT with invalid date (fails)
INSERT INTO v_recent_paid_orders (customer_id, order_date, status) 
VALUES (1, '2025-01-05', 'paid');

-- Try UPDATE to violate date constraint (fails)
UPDATE v_recent_paid_orders 
SET order_date = '2025-01-05' 
WHERE id = 1;

DELETE FROM orders WHERE status = 'new' AND order_date = '2025-01-15';

-- c) Recreate with CASCADED CHECK OPTION
DROP VIEW v_recent_paid_orders;
CREATE VIEW v_recent_paid_orders AS
SELECT id, customer_id, order_date, status
FROM v_paid_orders
WHERE order_date >= '2025-01-10'
WITH CASCADED CHECK OPTION;

-- Try INSERT with invalid status (now fails with CASCADED)
INSERT INTO v_recent_paid_orders (customer_id, order_date, status) 
VALUES (1, '2025-01-15', 'new');


-- Task 5: Non-updatable view
CREATE VIEW v_customer_orders AS
SELECT 
    c.id AS customer_id,
    c.full_name,
    o.id AS order_id,
    o.status
FROM customers c
JOIN orders o ON c.customer_id = o.customer_id;

-- Try UPDATE (will fail)
UPDATE v_customer_orders 
SET full_name = 'Updated Name' 
WHERE customer_id = 1;
-- Error: Views with JOINs are not automatically updatable


-- Task 6: MATERIALIZED VIEW
CREATE MATERIALIZED VIEW mv_vip_customers AS
SELECT id, full_name, city
FROM customers
WHERE is_vip = TRUE
WITH DATA;

SELECT * FROM mv_vip_customers;

-- Change data in base table
UPDATE customers 
SET is_vip = FALSE 
WHERE full_name = 'Alice Akhmetova';

-- Materialized view still shows old data
SELECT * FROM mv_vip_customers;

-- REFRESH to update
REFRESH MATERIALIZED VIEW mv_vip_customers;

SELECT * FROM mv_vip_customers;

-- Restore data
UPDATE customers 
SET is_vip = TRUE 
WHERE full_name = 'Alice Akhmetova';


-- Task 7: MATERIALIZED VIEW with aggregates
CREATE MATERIALIZED VIEW mv_sales_by_category AS
SELECT 
    p.category,
    SUM(oi.quantity * oi.unit_price) AS total_sales
FROM order_items oi
JOIN products p ON oi.product_id = p.id
GROUP BY p.category
WITH NO DATA;

-- Try SELECT (will fail - not populated)
SELECT * FROM mv_sales_by_category;

-- REFRESH to populate
REFRESH MATERIALIZED VIEW mv_sales_by_category;

SELECT * FROM mv_sales_by_category;


-- Task 8: CREATE OR REPLACE VIEW
CREATE VIEW v_city_customers AS
SELECT id, full_name, city
FROM customers;

SELECT * FROM v_city_customers;

-- Modify with CREATE OR REPLACE
CREATE OR REPLACE VIEW v_city_customers AS
SELECT id, full_name, city, UPPER(city) AS city_upper
FROM customers
WHERE city = 'Almaty';

SELECT * FROM v_city_customers;


-- Task 9: Roles and access control
CREATE ROLE reporting;
CREATE ROLE report_user WITH LOGIN PASSWORD 'report_password';

GRANT SELECT ON v_order_lines TO reporting;
GRANT SELECT ON mv_sales_by_category TO reporting;

GRANT reporting TO report_user;

-- report_user can now access v_order_lines and mv_sales_by_category
-- but NOT the base tables (order_items, orders, customers, products)


-- Task 10: Object ownership and REASSIGN OWNED
CREATE ROLE app_owner;

ALTER VIEW v_order_lines OWNER TO app_owner;

CREATE ROLE old_owner;

CREATE VIEW v_test_ownership AS
SELECT id, full_name FROM customers WHERE city = 'Astana';

ALTER VIEW v_test_ownership OWNER TO old_owner;

-- Check current owners
SELECT schemaname, viewname, viewowner 
FROM pg_views 
WHERE viewname IN ('v_order_lines', 'v_test_ownership');

-- REASSIGN ownership
REASSIGN OWNED BY old_owner TO app_owner;

-- Check again - v_test_ownership now owned by app_owner
SELECT schemaname, viewname, viewowner 
FROM pg_views 
WHERE viewname IN ('v_order_lines', 'v_test_ownership');

-- Clean up
DROP OWNED BY old_owner;
DROP ROLE old_owner;

-- REASSIGN OWNED transfers all objects from one role to another
-- DROP OWNED removes privileges and objects before dropping a role


-- Cleanup (optional)
/*
DROP VIEW IF EXISTS v_active_customers CASCADE;
DROP VIEW IF EXISTS v_order_lines CASCADE;
DROP VIEW IF EXISTS v_almaty_customers CASCADE;
DROP VIEW IF EXISTS v_paid_orders CASCADE;
DROP VIEW IF EXISTS v_recent_paid_orders CASCADE;
DROP VIEW IF EXISTS v_customer_orders CASCADE;
DROP VIEW IF EXISTS v_city_customers CASCADE;
DROP VIEW IF EXISTS v_test_ownership CASCADE;
DROP MATERIALIZED VIEW IF EXISTS mv_vip_customers;
DROP MATERIALIZED VIEW IF EXISTS mv_sales_by_category;
DROP ROLE IF EXISTS reporting;
DROP ROLE IF EXISTS report_user;
DROP ROLE IF EXISTS app_owner;
*/

