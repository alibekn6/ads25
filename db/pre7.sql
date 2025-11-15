CREATE TABLE customers (
                           customer_id INT PRIMARY KEY,
                           full_name   TEXT NOT NULL,
                           city        TEXT
);

CREATE TABLE orders (
                        order_id    INT PRIMARY KEY,
                        customer_id INT,
                        order_date  DATE,
                        status      TEXT
);

CREATE TABLE products (
                          product_id   INT PRIMARY KEY,
                          product_name TEXT NOT NULL,
                          category     TEXT
);

CREATE TABLE order_items (
                             order_id   INT,
                             product_id INT,
                             quantity   INT,
                             unit_price NUMERIC(10,2)
);


INSERT INTO customers (customer_id, full_name, city) VALUES
                                                         (1,'Alice','Almaty'),
                                                         (2,'Beka','Astana'),
                                                         (3,'Dana','Shymkent'),
                                                         (4,'Emir','Almaty');

INSERT INTO orders (order_id, customer_id, order_date, status) VALUES
                                                                   (100, 1, '2025-01-10', 'paid'),
                                                                   (101, 1, '2025-02-15', 'pending'),
                                                                   (102, 2, '2025-03-01', 'cancelled'),
                                                                   (103, 5, '2025-03-05', 'paid'),
                                                                   (104, 3, '2025-03-07', 'paid');

INSERT INTO products (product_id, product_name, category) VALUES
                                                              (10,'Laptop','Electronics'),
                                                              (20,'Mouse','Accessories'),
                                                              (30,'Keyboard','Accessories'),
                                                              (40,'Desk','Furniture'),
                                                              (50,'Monitor','Electronics');

INSERT INTO order_items (order_id, product_id, quantity, unit_price) VALUES
                                                                         (100, 10, 1, 500.00),
                                                                         (100, 20, 2,  25.00),
                                                                         (101, 50, 1, 150.00),
                                                                         (102, 20, 1,  25.00),
                                                                         (106, 30, 1,  30.00);
