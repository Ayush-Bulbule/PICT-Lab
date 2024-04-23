--
-- Database Trigger (All Types: Row level and Statement level triggers, Before and After Triggers). Write adatabase trigger on 
-- Library table. The System should keep track of the records that are being updated or deleted. The old value of updated or 
-- deleted records should be added in Library_Audit table.
-- Frame problem statement for writing Database Triggers of all types, inline with above statement. The problem statement 
-- should clearly state the requirements.


--1. Create table Libray:
create table library(
    bookid int,
    name varchar(30),
    author varchar(30)
);
--2. Create table library_audit:
create table library_audit(
    bookid int,
    name varchar(30),
    author varchar(30)
)

--3. insert data into library
insert into library(bookid,name,author)
values
(1,"C","Ayush"),
(2,"Java","Piyush"),
(3,"DSA","Karan"),
(4,"DS","Amir"),
(5,"CPP","Tej");

--4.  Create row trigger before update

--UPDATE Trigger
create trigger libray_update_trigger
before update on library
for each row
begin
    declare continue handler for 1062
    begin 
        signal sqlstate '45000'
        set message_text = 'Duplicate key error in trigger';
    end;
    insert into library_audit(bookid,name,author)
    values(old.bookid,old.name,old.author);
end;

-- DELETE Trigger
create trigger library_delete_trigger
before delete on library
for each row
begin   
    declare continue handler for 1062
    begin
        signal sqlstate '45000' set message_text = 'Duplicate key error in trigger';
    end;
    insert into library_audit(bookid,name,author)
    values(old.bookid,old.name,old.author);
end;

create trigger library_delete_statement_trigger
before update on library
begin
    insert into library_audit(bookid,name,author)
    select bookid, name,author
    from library
    where bookid in (select old.bookid from old);
end;

