--Named PL/SQL Block: PL/SQL Stored Procedure and Stored Function.
--Write a Stored Procedure namely proc_Grade for the categorization of student. 
--If marks scored by students in examination is <=1500 and marks>=990 then student
--will be placed in distinction category if marks scored are between 989 and900 category 
--is first class, if marks899and 825 category is Higher Second Class.
--Write a PL/SQL block to use procedure created with above requirement.
--Stud_Marks(name, total_marks)
--Result(Roll,Name, Class)
--1. Create Table stud_marks
create table stud_marks(
    id int primary key auto_increment,
    roll int,
    name varchar(30),
    total_marks int
);
--2. Create table result
create table result(
    roll int,
    name varchar(30),
    class varchar(30)
);
--3. Insert Data into stud_marks;
insert into stud_marks(roll, name, total_marks)
values (1, "Ayush", 1488),
    (2, "Piysh", 1300),
    (3, "Karan", 980),
    (4, "Ajey", 970),
    (5, "Yash", 857),
    (6, "David", 845);

-- 4. Create a PROCEDURE to calculate the grades
create procedure proc_result(in marks int, out class char(20)) 
begin 
    if(marks < 1500 && marks > 990) then
        set class = 'Distinction';
    end if;
    if(marks < 989 && marks > 890) then
        set class = 'First Class';
    end if;
    if(marks < 889 && marks > 825) then
        set class = 'Higher Second Class';
    end if;
    if(marks < 824 && marks > 750) then
        set class = 'Second Class';
    end if;
    if(marks < 749 && marks > 650) then
        set class = 'Passed';
    end if;
    if(marks < 649) then
        set class = 'Fail';
    end if;
end;


-- 5. Create a function to calculate and store marks
create function final_result(rno int) returns int deterministic 
begin
    declare fmarks integer;
    declare grade varchar(30);
    declare stud_name varchar(30);
    declare continue handler for not found begin return 0;
end;
    select sm.total_marks,
        sm.name into fmarks,
        stud_name
    from stud_marks as sm
    where sm.roll = rno;
 
    call proc_result(fmarks, @grade);
 
    insert into result(roll, name, class)
    values(rno, stud_name, @grade);
    return rno;
end;
--
select final_result(3);