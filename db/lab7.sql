-- Lab 7


-- task 1
SELECT 
    o.order_id,
    o.order_date,
    o.status,
    c.full_name
FROM orders o
INNER JOIN customers c ON o.customer_id = c.customer_id;


-- Task 2: 
SELECT 
    c.customer_id,
    c.full_name,
    COUNT(o.order_id) AS orders_count
FROM customers c
LEFT JOIN orders o ON c.customer_id = o.customer_id
GROUP BY c.customer_id, c.full_name
ORDER BY c.customer_id;


-- Task 3: 
SELECT 
    o.order_id,
    o.customer_id
FROM customers c
RIGHT JOIN orders o ON c.customer_id = o.customer_id
WHERE c.customer_id IS NULL;


-- Task 4:
SELECT 
    oi.order_id,
    oi.product_id,
    oi.quantity,
    oi.unit_price,
    p.product_name
FROM order_items oi
INNER JOIN products p USING (product_id);


-- Task 5
SELECT 
    o.order_id,
    c.full_name,
    p.product_name,
    oi.quantity
FROM orders o
INNER JOIN customers c ON o.customer_id = c.customer_id
INNER JOIN order_items oi ON o.order_id = oi.order_id
INNER JOIN products p ON oi.product_id = p.product_id
WHERE o.status = 'paid';


-- taskl 6: 
SELECT 
    o.order_id,
    COALESCE(SUM(oi.quantity * oi.unit_price), 0) AS order_total
FROM orders o
LEFT JOIN order_items oi ON o.order_id = oi.order_id
GROUP BY o.order_id
ORDER BY o.order_id;



-- task 7
SELECT 
    c.customer_id,
    c.full_name,
    o.order_id,
    o.status
FROM customers c
FULL OUTER JOIN orders o ON c.customer_id = o.customer_id
ORDER BY COALESCE(c.customer_id, o.order_id);


-- Task 8
SELECT 
    o.order_id,
    o.customer_id,
    c.full_name,
    o.status
FROM orders o
LEFT JOIN customers c ON o.customer_id = c.customer_id
ORDER BY o.order_id;


-- Task 9:
SELECT 
    oi.order_id,
    COUNT(*) AS items_count,
    SUM(oi.quantity) AS total_qty
FROM order_items oi
GROUP BY oi.order_id
ORDER BY oi.order_id;


-- task 10.
SELECT 
    p.product_id,
    p.product_name,
    COALESCE(SUM(oi.quantity), 0) AS total_sold
FROM products p
LEFT JOIN order_items oi ON p.product_id = oi.product_id
GROUP BY p.product_id, p.product_name
ORDER BY p.product_id;