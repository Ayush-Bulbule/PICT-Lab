-- Assignment No 2A (Employee Schema)
-- Create following tables in MYSQL
-- ● Employee( Emp_id, Dept_id, Emp_fname, Emp_lname, Emp_Position, Emp_salary,Emp_JoinDate)
-- ● Dept ( Dept_id, Dept_name,Dept_location ,)
-- ● Project( Proj_id,Dept_id ,Proj_Name,Proj_Location,Proj_cost,Proj_year)
-- Create view (simple), index, sequence and synonym based on above tables.
-- Note: Use referential integrity constraints while creating tables with on delete cascade
-- options.
-- 1. Creating Table Employee;
;
create table employee(
    emp_id int primary key auto_increment,
    dept_id int,
    emp_fname varchar(255),
    emp_lname varchar(255),
    emp_position varchar(255),
    emp_salary int,
    emp_join_date varchar(255)
);
--creating table dept
create table dept(
    dept_id int primary key auto_increment,
    dept_name varchar(255),
    dept_location varchar(255)
);
--Creating table projects
create table projects(
    proj_id int primary key auto_increment,
    dept_id int,
    proj_name varchar(255),
    proj_location varchar(255),
    proj_cost int,
    proj_year int,
    foreign key (dept_id) references dept(dept_id) on delete cascade
);
--Add Foreign Key in Employees
alter table employee
add constraint fk_emp_dept foreign key (dept_id) references dept(dept_id);
--Insert into table dept
insert into dept(dept_name, dept_location)
values ("Production", "Banglore");
insert into dept(dept_name, dept_location)
values ("Administration", "Mumbai");
insert into dept(dept_name, dept_location)
values ("Finance", "Mumbai");
insert into dept(dept_name, dept_location)
values ("IT", "Pune");
insert into dept(dept_name, dept_location)
values ("Marketing", "Mumbai");
insert into dept(dept_name, dept_location)
values ("Bussiness", "Nashik");
insert into dept(dept_name, dept_location)
values ("Sales", "Nagpur");
-- Insert Data into employees
-- Insert Data
insert into employee (
        dept_id,
        emp_fname,
        emp_lname,
        emp_position,
        emp_salary,
        emp_join_date
    )
values (
        4,
        'Ayush',
        'Bulbule',
        'Project Manager',
        -- Corrected space in 'Project Manager'
        1500000,
        '2024-02-05'
    );
-- insertn more data
insert into employee (
        dept_id,
        emp_fname,
        emp_lname,
        emp_position,
        emp_salary,
        emp_join_date
    )
values (
        1,
        'Ajinkya',
        'Bhosle',
        'Manager',
        800000,
        '2022-06-12'
    ),
    (
        3,
        'Bhushan',
        'Joshi',
        'Accountant',
        500000,
        '2025-08-12'
    ),
    (
        2,
        'Amit',
        'Kumar',
        'HR Manager',
        700000,
        '2023-02-15'
    ),
    (
        4,
        'Sneha',
        'Verma',
        'Software Engineer',
        90000,
        '2024-11-20'
    ),
    (
        5,
        'Priya',
        'Sharma',
        'Marketing Coordinator',
        600000,
        '2023-07-10'
    ),
    (
        6,
        'Rahul',
        'Gupta',
        'Business Analyst',
        750000,
        '2024-04-30'
    );
-- insert data into projects
insert into projects (
        dept_id,
        proj_name,
        proj_location,
        proj_cost,
        proj_year
    )
values (
        4,
        "Development of CRM",
        "Pune",
        50000,
        2022
    );
-- Insert Multiple values
insert into projects (
        dept_id,
        proj_name,
        proj_location,
        proj_cost,
        proj_year
    )
values (
        1,
        'Design of New Products',
        'Bangalore',
        75000,
        2023
    ),
    (
        3,
        'Financial Analysis System',
        'Mumbai',
        40000,
        2022
    ),
    (2, 'HR Training Program', 'Mumbai', 20000, 2023),
    (4, 'IT System Upgrade', 'Pune', 60000, 2024),
    (5, 'Marketing Campaign', 'Mumbai', 35000, 2023),
    (
        6,
        'Business Expansion Plan',
        'Nashik',
        80000,
        2024
    ),
    (
        7,
        'Sales Strategy Revamp',
        'Nagpur',
        30000,
        2023
    );
-- Display all Employee details with Department 'Finance' and 'IT' and Employee first name starting with 'p' or 'h'.
select *
from employee
where dept_id in (
        select dept_id
        from dept
        where dept_name = 'Finance'
            or dept_name = 'IT'
    )
    and emp_fname like 'p%'
    or emp_fname like 'a%';
--    
-- Lists the number of different Employee Positions.
select distinct count(emp_position)
from employee;
-- modifying the employee as we need datatype date in the employee
alter table employee drop column emp_join_date;
-- adding joining date again
alter table employee
add column emp_join_date date;
-- ; Insert Data
update employee
set emp_join_date = '2020-12-1'
where emp_id = 1;
-- insetring random dates (generated)
UPDATE employee
SET emp_join_date = DATE_ADD('2020-12-01', INTERVAL FLOOR(RAND() * 365) DAY)
WHERE emp_join_date IS NULL;
--add column  dob to employee table
alter table employee
add column emp_dob date;
-- insert random dob
update employee
set emp_dob = date_add('2001-12-01', interval floor(rand() * 365) day)
where emp_dob is null;
update employee
set emp_salary
select *
from projects
order by proj_id desc
limit 1;
select *
from projects
where proj_id = (
        select max(proj_id)
        from projects
    );
-- average of project cose
select avg(proj_cost)
from projects;