-- PLSQL
-- Table 1: Sales Table
CREATE TABLE salesdata(
    SalesID INT NOT NULL AUTO_INCREMENT,
    SalesDate DATE NOT NULL,
    SalesAmount DECIMAL(10, 2) NOT NULL,
    SalesTax DECIMAL(10, 2) NOT NULL,
    SalesTotal DECIMAL(10, 2) NOT NULL,
    PRIMARY KEY (SalesID)
);
-- Table 2:  Table
INSERT INTO Salesdata (SalesDate, SalesAmount, SalesTax, SalesTotal)
VALUES ('2023-01-01', 100.00, 18.00, 118.00),
    ('2023-01-02', 150.00, 27.00, 177.00),
    ('2023-01-03', 200.00, 36.00, 236.00),
    ('2023-01-04', 120.00, 21.60, 141.60),
    ('2023-01-05', 180.00, 32.40, 212.40),
    ('2023-01-06', 220.00, 39.60, 259.60),
    ('2023-01-07', 130.00, 23.40, 153.40),
    ('2023-01-08', 160.00, 28.80, 188.80),
    ('2023-01-09', 210.00, 37.80, 247.80),
    ('2023-01-10', 140.00, 25.20, 165.20);
--
-- Employees Table  
create table emps(
    id int primary key auto_increment,
    name varchar(255),
    salary int,
    role varchar(255)
);
--
INSERT INTO emps (name, salary, role)
VALUES ('John Doe', 50000, 'Manager'),
    ('Jane Smith', 55000, 'Engineer'),
    ('Mike Johnson', 60000, 'Developer'),
    ('Emily Williams', 52000, 'Designer'),
    ('David Brown', 48000, 'Analyst'),
    ('Sarah Clark', 53000, 'Manager'),
    ('Michael Lee', 62000, 'Developer'),
    ('Emma Davis', 54000, 'Engineer'),
    ('William Hall', 51000, 'Designer'),
    ('Olivia Moore', 49000, 'Analyst');
-- Procedures:
-- 1:GetAllEmps
CREATE PROCEDURE getAllSales() BEGIN
select *
from salesdata;
END;
--


