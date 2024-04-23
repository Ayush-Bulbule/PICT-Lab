-- Unnamed PL/SQL code block: Use of Control structure and Exception handling is mandatory.
-- Write a PL/SQL block of code for the following requirements:-
-- Schema:
-- 1. Borrower(Roll, Name, DateofIssue, NameofBook, Status)
-- 2. Fine (Roll, Date, Amt)
-- Accept Roll & N ame of book from user.
-- Check the number of days (from date of issue), if days are between 15 to 30 then fine amount will be Rs 5per day.
-- If no. of days>30, per day fine will be Rs 50 per day & for days less than 30, Rs. 5 per day.
-- After submitting the book, status will change from I to R.
-- If condition of fine is true, then details will be stored into fine table.
-- Frame the problem statement for writing PL/SQL block inline with above statement.
CREATE TABLE borrower(
    roll int,
    name varchar(45),
    doi date,
    book_name varchar(45),
    status varchar(45)
);
--crea table
CREATE TABLE fine(
    rollno int,
    date date,
    amount int
);
-- Insert Data into borrowers
INSERT INTO borrower(roll, name, doi, book_name, status)
VALUES (
        10,
        "Ayush",
        "2023-10-02",
        "Programming C",
        "issued"
    ),
    (11, "Karan", "2023-10-24", "DBMS", "issued"),
    (12, "Piyush", "2023-10-12", "DS", "issued"),
    (
        13,
        "Kunal",
        "2023-10-13",
        "Programming C",
        "issued"
    ),
    (
        14,
        "Yash",
        "2023-10-18",
        "DSA with JAVA",
        "issued"
    ),
    (15, "Kumar", "2023-10-29", "CNS", "issued");

-- Schema:
-- 1. Borrower(Roll, Name, DateofIssue, NameofBook, Status)
-- 2. Fine (Roll, Date, Amt)    
-- Write a procedure to calculate fine
create procedure calc_fine(roll_new int, book_name_new varchar(20)) begin
    declare x integer;
    declare continue handler for not found begin
        select 'NOT FOUND';
    end;
    select datediff(curdate(), doi) into x  
    from borrower
    where roll = roll_new and book_name = book_name_new;
    --Check for fine
    if(x > 15 && x < 30) then
        insert into fine(rollno, date, amount)
        values(roll_new, curdate(), (x * 5));
    end if;
    if(x > 30) then
    insert into fine(rollno, date, amount)
        values(roll_new, curdate(), (x * 50));
    end if;
    update borrower
    set status = 'returned'
    where roll = roll_new and book_name = book_name_new;
end;
-- call the Procedure for the user roll