CREATE DATABASE db_machine_prob1;

USE  db_machine_prob1;
DROP TABLE tblstaff;

CREATE TABLE tblstaff (
	
    StaffNo int,
	BranchNo varchar (50),
	LName varchar(50),
    FName varchar(50),
    Designation varchar(50),
    Salary int (50),
    City varchar(50),
    Street varchar(50),
    PostCode int (10)

);

-- CREATE TABLE branch

INSERT INTO tblstaff () VALUES (100, 'Bravo', 'Johnny', 'Manager', 1000000, 'London', 'Cornelia', 2012);
INSERT INTO tblstaff () VALUES (101, 'Xailer', 'Rolex', 'Assistant', 40000, 'Pampanga', 'Mexico', 2010);
INSERT INTO tblstaff () VALUES (102, 'Hizer', 'Rosgen', 'Supervisor', 500000, 'Glasglow', 'Ewan', 2008);
INSERT INTO tblstaff (StaffNo, LName, FName, Designation, Salary) VALUES (103, 'Maglalang', 'MR Rey', 'Assistant', 20000);
INSERT INTO tblstaff (StaffNo, LName, FName, Designation, Salary, BranchNo) VALUES (104, 'Bernal', 'Leonalyn', 'Supervisor', 200000, 'B005');
INSERT INTO tblstaff (StaffNo, LName, FName, Designation, Salary, BranchNo) VALUES (105, 'Ferrer', 'Sean Kenji', 'Manager', 500000, 'B005');


-- Designation [Assistant, Manager, Supervisor, ]

-- 15.) Set Membership IN (OR Clause)
SELECT StaffNo, LName, FName, Designation FROM tblstaff WHERE Designation

IN ('Manager','Supervisor');

SELECT StaffNo, LName, FName, Salary FROM tblstaff WHERE Salary IN (30000,9000); -- kung ano ung nakalagay sa parenthesis un ung condition  if salary is exactly as 30,000 or 9,000

-- *Negation
SELECT StaffNo, LName, FName, Designation FROM tblstaff WHERE Designation = 'Manager' OR Designation = 'Supervisor';

 SELECT * FROM tblstaff;
 
 UPDATE tblstaff SET Salary = 30000 WHERE StaffNo = 103;

 SELECT StaffNo, LName, FName, Salary FROM tblstaff WHERE Salary = 30000 OR Salary = 9000;

-- 16.) Pattern Matching (Wild card search using %)
 SELECT StaffNo, LName, FName FROM tblstaff WHERE StaffNo LIKE 'SG%';

 SELECT StaffNo, LName, FName FROM tblstaff WHERE StaffNo LIKE 'SL%';

 SELECT StaffNo, LName, FName FROM tblstaff WHERE StaffNo LIKE '%1';

 SELECT StaffNo, LName, FName FROM tblstaff WHERE StaffNo LIKE '%e%';

SELECT StaffNo, LName, FName FROM tblstaff WHERE StaffNo LIKE '%ee%';

-- 17.) Single Column Ordering
 SELECT * FROM tblstaff ORDER BY LName ASC;
SELECT * FROM tblstaff ORDER BY LName DESC;
SELECT * FROM tblstaff ORDER BY FName DESC;
 SELECT * FROM tblstaff ORDER BY StaffNo ASC;
 SELECT * FROM tblstaff ORDER BY Salary ASC;

SELECT staffNo, LName, FName FROM tblstaff WHERE staffNo LIKE 'SG%' ORDER BY LName ASC; ;-- para saan ang SG amp

SELECT staffNo, LName, FName, Salary FROM tblstaff WHERE Salary IN(30000,9000) ORDER BY Lname ASC;
SELECT * FROM tblstaff;

 SELECT * FROM tblstaff WHERE Designation='Assistant' ORDER BY LName ASC;

-- 18.) Using COUNT
-- *Count All
SELECT COUNT(*) AS TotalStaff FROM tblstaff;

-- *Count with comparison search
SELECT COUNT(*) AS MYCOUNT FROM tblstaff WHERE BranchNo='B005';

SELECT COUNT(*) AS TotalAssistant FROM tblstaff WHERE Designation='Assistant';

 SELECT COUNT(*) AS TotalDesignation FROM tblstaff WHERE Designation IN('Manager','Assistant'); -- 4

SELECT COUNT(*) AS TotalEmployee FROM tblstaff WHERE LName LIKE 'B%'; -- 2


SELECT * FROM tblstaff;
-- 19.) Use of COUNT(DISTINCT)
 SELECT COUNT(BranchNo) AS MYCOUNT FROM tblstaff;

SELECT COUNT(DISTINCT BranchNo) AS MYCOUNT FROM tblstaff; -- pag distinct ung unique data

-- 20.) Use of COUNT and SUM
 SELECT COUNT(staffNo) AS Totalstaff, SUM(Salary) AS TotalSalary FROM tblstaff;

 SELECT COUNT(staffNo) AS Totalstaf, SUM(Salary) AS TotalSalary FROM tblstaff WHERE Designation='Assistant';

 SELECT COUNT(staffNo) AS Totalstaff, SUM(Salary) AS TotalSalary FROM tblstaff WHERE BranchNo='B003';

 SELECT SUM(Salary) AS TotalSalary FROM tblstaff WHERE Designation = 'Manager';

-- *Aggregate Functions (SUM, COUNT, MIN, MAX, AVG)

-- 21.) Using MIN, MAX and AVG
-- ung pinaka minimum sa set of data at maximum; average salary [average ng lahat ng data]
SELECT MIN(Salary) AS LowSalary, MAX(Salary) as HighSalary, AVG(Salary) AS AverageSalary FROM tblstaff;

 SELECT MIN(Salary) AS LowSalary From tblstaff WHERE Designation='Assistant';
SELECT MAX(Salary) As MaxSalary FROM tblstaff WHERE BranchNo = 'B003';
 SELECT AVG(Salary) As AverageSalary FROM tblstaff WHERE BranchNo = 'B005';

-- 22.) Using GROUP BY
SELECT Designation, COUNT(staffNo) AS Totalstaff, SUM(Salary) AS TotalSalary, AVG(Salary) AS Average FROM tblstaff GROUP BY Designation ORDER BY Designation ASC;

 SELECT BranchNo, COUNT(staffNo) AS Totalstaff, SUM(Salary) AS TotalSalary, AVG(Salary) AS Average FROM tblstaff GROUP BY BranchNo ORDER BY BranchNo ASC;

-- 23.) Use of HAVING
SELECT Designation, COUNT(staffNo) AS Totalstaff, SUM(Salary) AS TotalSalary, AVG(Salary) AS Average FROM tblstaff GROUP BY Designation HAVING COUNT(staffNo) > 1 ORDER BY Designation ASC;

SELECT Designation, COUNT(staffNo) AS Totalstaff, SUM(Salary) AS TotalSalary, AVG(Salary) AS Average FROM tblstaff GROUP BY Designation HAVING AVG(Salary) < 15000 ORDER BY Designation ASC;

-- 24.) Create a table Branch

CREATE TABLE tblBranch (

	BranchNo varchar(50),
    City varchar (50),
    Street varchar(50),
    PostCode int (10)

);

INSERT INTO tblBranch VALUE 
('B001'),
('B002'),
('B003'),
('B004'),
('B005'),
('B006'),
('B007');

SELECT * FROM tblBranch;
-- 25.) Using SUB Query

-- PROBLEEEEEm

 SELECT staffNo, LName, FName, BranchNo FROM tblstaff WHERE BranchNo =(SELECT BranchNo FROM tblBranch WHERE BranchNo='B006');

 SELECT staffNo, LName, Fname, BranchNo FROM tblstaff WHERE BranchNo =(SELECT BranchNo FROM tblBranch WHERE BranchNo='B005');

SELECT staffNo, LName, FName, BranchNo FROM tblstaff WHERE BranchNo =(SELECT BranchNo FROM tblBranch WHERE BranchNo='B004');

-- 26.) Using Subquery with Aggregate function
SELECT staffNo, LName, FName, Salary FROM tblstaff WHERE Salary > (SELECT AVG(Salary) FROM tblstaff);

 SELECT staffNo, FName, Salary FROM tblstaff WHERE Salary <= (SELECT MIN(Salary) FROM tblstaff);
SELECT MIN(Salary) FROM tblstaff;
INSERT INTO tblstaff VALUES (106, 'Hi-zero', 'Rokhai', 'Assistant', 1000, 'B003');
-- 27.) Using simple JOIN (connecting 2 tables).
SELECT * FROM tblstaff;
 SELECT * FROM tblbranch;
 
UPDATE tblstaff SET City = 'Pampanga' , Street = 'San Fernando', PostCode = 2012 where StaffNo = 102;
 
 -- Street varchar (50),



 SELECT staffNo, LName, FName, br.BranchNo, Street, City, PostCode FROM tblstaff st, tblBranch br WHERE st.BranchNo = br.BranchNo; -- tama tama
 
 SELECT * FROM tblstaff st, tblBranch br WHERE st.BranchNo = br.BranchNo;

 SELECT tblstaff.staffNo,LName,FName,tblbranch.BranchNo,Street,City,PostCode FROM tblstaff, tblBranch WHERE tblstaff.BranchNo = tblbranch.BranchNo;

 SELECT staffNo,FName,Designation,Salary,br.BranchNo,PostCode FROM tblstaff st, tblBranch br WHERE st.BranchNo = br.BranchNo;

 SELECT staffNo,FName,Designation,Salary,br.BranchNo,PostCode,Street FROM tblstaff st, tblBranch br WHERE st.BranchNo='B005' AND st.BranchNo = br.BranchNo;

SELECT staffNo,LName,FName,Designation,Salary,br.BranchNo,PostCode FROM tblstaff st, tblBranch br WHERE StaffNo LIKE 'SG%' AND st.BranchNo = br.BranchNo;




 Create table Schedule1
 (
 BranchNo varchar(15),
 StartTime varchar(15),
 EndTime varchar(15)
);

 INSERT INTO Schedule1 VALUES
 ('B003','8:00 AM','5:00 PM'),
 ('B004','7:00 AM','4:00 PM'),
 ('B005','9:00 AM','6:00 PM'),
 ('B007','10:00 AM','9:00 PM');

 SELECT * FROM schedule;
 SELECT * FROM schedule1;

CREATE TABLE branch;

select * from tblbranch;
select * from tblstaff;
UPDATE tblstaff SET City = 'London' WHERE StaffNo = 103;

ALTER TABLE tblbranch ADD PostCode int(10);
UPDATE  tblbranch SET PostCode = 2012 WHERE BranchNo = 'B001';

 Create table Schedule
(
 City varchar(50),
 StartTime varchar(50),
 EndTime varchar(50)
);

 INSERT INTO schedule VALUES
 ('London','8:00 AM','5:00 PM'),
 ('Glasglow','7:00 AM','4:00 PM'),
 ('Bristol','9:00 AM','6:00 PM'),
 ('Aberdeen','10:00 AM','9:00 PM');

SELECT BranchNo,Street,branch.City,PostCode,StartTime,EndTime FROM tblbranch  as branch, schedule WHERE branch.City = schedule.City;

 SELECT StaffNo, LName,FName, staff.BranchNo,StartTime,EndTime FROM tblstaff as staff, schedule1 WHERE staff.BranchNo = schedule1.BranchNo;

-- 28.) Joining 3 Tables
SELECT StaffNo, LName, FName, staff.BranchNo, branch.City, StartTime,EndTime FROM tblstaff as staff, tblbranch as branch,  schedule WHERE staff.branchno = branch.branchno AND branch.city = schedule.city;




-- alisin nalang sex dman sya litaw sa ibang execution ng SELECT
 SELECT staffNo,LName,FName,Designation,staff.BranchNo,staff.City,staff.PostCode,StartTime,EndTime FROM tblstaff as staff , tblbranch as branch,  schedule1 WHERE staff.Branchno = branch.BranchNo AND branch.BranchNo = schedule1.BranchNo;

 SELECT staffNo, FName, LName, st.BranchNo, st.Street, st.City, st.PostCode FROM tblstaff st, tblbranch br WHERE st.BranchNo = 'B004' AND st.BranchNo = br.BranchNo;

 SELECT staffNo, FName, LName, st.BranchNo, st.Street,st.City,st.PostCode FROM tblstaff st, tblbranch br WHERE st.BranchNo = 'B003' AND st.BranchNo = br.BranchNo ORDER BY LName ASC;

-- 29.) Deleting Specific records.
 -- USE db_initials_matthew
SELECT * FROM tblstaff;
UPDATE tblstaff SET Salary = 9000 WHERE StaffNo = 103;


 DELETE FROM tblstaff WHERE staffNo = 'SG14';

 DELETE FROM tblstaff WHERE salary = 9000;

 DELETE FROM tblstaff WHERE LName LIKE '%e%';

-- 30.) Editing Record in the table
 UPDATE tblstaff SET Salary = 30000 WHERE StaffNo='SG5'; -- StaffNo can be anything

-- USE db_pre_mp1_initials_matthew
-- SELECT * FROM tblStudinfo 
-- SELECT * FROM tblStudinfo WHERE Course='BSIT' >> (3 Records)

-- UPDATE tblstudinfo SET Subject='IT101' WHERE Course = 'BSIT'
-- SELECT * FROM tblstudinfo WHERE FGrade < 74

-- UPDATE tblstudinfo SET FGrade = 75 WHERE FGrade < 74
-- UPDATE tblstudinfo SET FGrade = 90, MGrade = 75, FGrade = 99 WHERE StudNo = '001'

-- SELECT * FROM tblstudinfo WHERE StudNo='001'