-- 
--
CREATE TABLE borrower(
    id INT primary key auto_increment,
    name varchar(45),
    issue_date date,
    book_name varchar(45),
    status varchar(45)
);
--crea table
CREATE TABLE fine(
    id int primary key auto_increment,
    rollno int,
    date date,
    amount int
)