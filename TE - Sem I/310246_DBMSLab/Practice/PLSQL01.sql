CREATE PROCEDURE GetAllOrders() BEGIN
SELECT *
FROM orders;
END;
--Procedure 2
CREATE PROCEDURE GetOrderById(IN p_id INT) BEGIN
SELECT *
FROM products
WHERE product_id = p_id;
END;
/ / DELIMITER;
-- Procedure 3