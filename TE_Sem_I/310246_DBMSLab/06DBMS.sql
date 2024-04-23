--Cursors: (All types: Implicit, Explicit, Cursor FOR Loop, Parameterized Cursor)
--Write a PL/SQL block of code using parameterized Cursor, that will merge the 
--data available in the newly created table N_EmpId with the data available in the table O_EmpId.
--If the data in the first table already exist in the second table then that data should be skipped.
-- 1. Create old table
create table o_emp(
    e_id int,
    fname varchar(45),
    lname varchar(45),
    salary int
);
-- 2. create new table
create table n_emp(
    e_id int primary key,
    fname varchar(45),
    lname varchar(45),
    salary int
);
--3. Insert data in old table
insert into o_emp (e_id, fname, lname, salary)
values (1,'Ayush', 'B', 20000),
    (2,'Piyush', 'Joih', 30000),
    (3,'Kumar', 'Yadav', 34000),
    (4,'Ash', 'M', 40000),
    (5,'Ajey', 'N', 30000),
    (6,'Yash', 'S', 40000);
--4. Create a cursor
--CURSOR with loop
create procedure copyEmp() 
begin
    declare done int default false;
    declare n_e_id int;
    declare n_fname varchar(45);
    declare n_lname varchar(45);
    declare n_salary int;

    declare cur cursor for 
        select e_id, fname, lname, salary from o_emp;
    
    declare continue handler for not found set done = true;
    open cur;
    read_loop :LOOP 
        fetch cur into n_e_id, n_fname, n_lname, n_salary;
    
    if done then 
        leave read_loop;
    end if;
        if not exists(select 1 from n_emp where n_emp.e_id=n_e_id)
        then 
            insert into n_emp(e_id, fname,lname,salary) values(n_e_id,n_fname,n_lname,n_salary);
        end if;
    end loop;
    close cur;
end;

-- cal the procedure
call compyEmp();
--check 
select *
from n_emp;



CREATE PROCEDURE copyData()
BEGIN
    DECLARE done INT DEFAULT FALSE;
    DECLARE e_id INT;
    DECLARE fname VARCHAR(50);
    DECLARE lname VARCHAR(50);
    DECLARE salary INT;
    
    DECLARE cur CURSOR FOR SELECT e_id, fname, lname, salary FROM o_emp;
    DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;
    
    OPEN cur;
    
    read_loop: LOOP
        FETCH cur INTO e_id, fname, lname, salary;
        
        IF done THEN
            LEAVE read_loop;
        END IF;
        
        -- Check if the e_id already exists in n_emp to avoid duplication
        IF NOT EXISTS (SELECT 1 FROM n_emp WHERE n_emp.e_id = e_id) THEN
            -- Insert the row into n_emp if it doesn't exist
            INSERT INTO n_emp (e_id, fname, lname, salary) VALUES (e_id, fname, lname, salary);
        END IF;
    END LOOP;
    
    CLOSE cur;

END;