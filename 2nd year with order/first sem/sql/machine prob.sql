CREATE DATABASE db_machine_prob;

USE db_machine_prob;


create table tblstaff (

	StaffNo int,
    BranchNo varchar(50),
	LName varchar(50),
	FName varchar(50),
    Designation varchar(50),
	Salary int
);


 INSERT INTO tblstaff VALUES
('SG1', 'B003','Aethan', 'Tagle', 'Manager', '30000');
-- ('100', 'B001','Tagle', 'Aries', 'Manager', '30000'),
-- ('101', 'B002','balatbat', 'Angelo', 'Supervisor', '9000');

-- 15.) Set Membership IN (OR Clause)
SELECT StaffNo, LName, FName, Designation FROM tblstaff WHERE Designation
IN ('Manager', 'Supervisor')
;

SELECT StaffNo, LName, FName, Salary FROM tblstaff WHERE Salary
IN (30000, 9000)
;

-- *Negation
SELECT StaffNo, LName, FName, Designation FROM tblstaff WHERE Designation = 'Manager' OR Designation = 'Supervisor'
 ;
SELECT StaffNo, LName, FName, Salary FROM tblstaff WHERE Salary = 30000 OR Salary = 9000
;
-- 16.) Pattern Matching (Wild card search using %)
SELECT StaffNo, LName, FName FROM tblstaff WHERE StaffNo LIKE 'SG%'
;
SELECT StaffNo, LName, FName FROM tblstaff WHERE StaffNo LIKE 'SL%'
;
SELECT StaffNo, LName, FName FROM tblstaff WHERE StaffNo LIKE '%1'
;
SELECT StaffNo, LName, FName FROM tblstaff WHERE LName LIKE '%e%'
;
SELECT StaffNo, LName, FName FROM tblstaff WHERE StaffNo LIKE '%ee%'
;
-- 17.)Single Column Ordering
-- SELECT * FROM tblstaff ORDER BY LName ASC
-- SELECT * FROM tblstaff ORDER BY LName DESC
-- SELECT * FROM tblstaff ORDER BY FName DESC
-- SELECT * FROM tblstaff ORDER BY StaffNo ASC
-- SELECT * FROM tblstaff ORDER BY Salary ASC

-- SELECT staffNo, LName, FName FROM tblstaff WHERE staffNo LIKE 'SG%' ORDER BY LName ASC

-- SELECT staffNo, LName, FName, Salary FROM tblstaff WHERE Salary IN(30000,9000) ORDER BY Lname ASC
-- SELECT * FROM tblstaff

-- SELECT * FROM tblstaff WHERE Designation='Assistant' ORDER BY LName ASC

-- 18.) Using COUNT
-- *Count All
-- SELECT COUNT(*) AS TotalStaff FROM tblstaff

-- *Count with comparison search
-- SELECT COUNT(*) AS MYCOUNT FROM tblstaff WHERE BranchNo='B005'

-- SELECT COUNT(*) AS TotalAssistant FROM tblstaff WHERE Designation='Assistant'

-- SELECT COUNT(*) AS TotalDesignation FROM tblstaff WHERE Designation IN('Manager','Assistant')

-- SELECT COUNT(*) AS TotalEmployee FROM tblstaff WHERE LName LIKE 'B%'

-- 19.) Use of COUNT(DISTINCT)
-- SELECT COUNT(BranchNo) AS MYCOUNT FROM tblstaff

-- SELECT COUNT(DISTINCT BranchNo) AS MYCOUNT FROM tblstaff

-- 20.) Use of COUNT and SUM
SELECT COUNT(staffNo) AS Totalstaff, SUM(Salary) AS TotalSalary FROM tblstaff;

SELECT COUNT(staffNo) AS Totalstaf, SUM(Salary) AS TotalSalary FROM tblstaff WHERE Designation='Assistant';

-- SELECT COUNT(staffNo) AS Totalstaff, SUM(Salary) AS TotalSalary FROM tblstaff WHERE BranchNo='B003';

-- SELECT SUM(Salary) AS TotalSalary FROM tblstaff WHERE Designation = 'Manager';

-- *Aggregate Functions (SUM, COUNT, MIN, MAX, AVG)

-- 21.) Using MIN, MAX and AVG
-- SELECT MIN(Salary) AS LowSalary, MAX(Salary) as HighSalary, AVG(Salary) AS AverageSalary FROM tblstaff

-- SELECT MIN(Salary) AS LowSalary From tblstaff WHERE Designation='Assistant'
-- SELECT MAX(Salary) As MaxSalary FROM tblstaff WHERE BranchNo = 'B003'
-- SELECT AVG(Salary) As AverageSalary FROM tblstaff WHERE BranchNo = 'B005'

-- 22.) Using GROUP BY
-- SELECT Designation, COUNT(staffNo) AS Totalstaff, SUM(Salary) AS TotalSalary, AVG(Salary) AS Average FROM tblstaff GROUP BY Designation ORDER BY Designation ASC

-- SELECT BranchNo, COUNT(staffNo) AS Totalstaff, SUM(Salary) AS TotalSalary, AVG(Salary) AS Average FROM tblstaff GROUP BY BranchNo ORDER BY BranchNo ASC

-- 23.) Use of HAVING
-- SELECT Designation, COUNT(staffNo) AS Totalstaff, SUM(Salary) AS TotalSalary, AVG(Salary) AS Average FROM tblstaff GROUP BY Designation HAVING COUNT(staffNo) > 1 ORDER BY Designation ASC

-- SELECT Designation, COUNT(staffNo) AS Totalstaff, SUM(Salary) AS TotalSalary, AVG(Salary) AS Average FROM tblstaff GROUP BY Designation HAVING AVG(Salary) < 15000 ORDER BY Designation ASC

-- 24.) Create a table Branch
-- 25.)Using SUB Query
-- SELECT staffNo, LName, FName, BranchNo FROM tblstaff WHERE BranchNo =(SELECT BranchNo FROM tblBranch WHERE BranchNo='B006')

-- SELECT staffNo, LName, Fname, BranchNo FROM tblstaff WHERE BranchNo =(SELECT BranchNo FROM tblBranch WHERE BranchNo='B005')

-- SELECT staffNo, LName, FName, BranchNo FROM tblstaff WHERE BranchNo =(SELECT BranchNo FROM tblBranch WHERE BranchNo='B004')

-- 26.) Using Subquery with Aggregate function
-- SELECT staffNo, LName, FName, Salary FROM tblstaff WHERE Salary > (SELECT AVG(Salary) FROM tblstaff)

-- SELECT staffNo, FName, Salary FROM tblstaff WHERE Salary < (SELECT MIN(Salary) FROM tblstaff)

-- 27.) Using simple JOIN (connecting 2 tables).
-- SELECT * FROM tblstaff
-- SELECT * FROM tblbranch

-- SELECT staffNo, LName, FName, br.BranchNo, Street, City, PostCode FROM tblstaff st, tblBranch br WHERE st.BranchNo = br.BranchNo

-- SELECT * FROM tblstaff st, tblBranch br WERE st.BranchNo = br.BranchNo

-- SELECT tblstaff.staffNo,LName,FName,tblbranch.BranchNo,Street,City,PostCode FROM tblstaff, tblBranch WHERE tblstaff.BranchNo = tblbranch.BranchNo

-- SELECT staffNo,FName,Designation,Salary,br.BranchNo,PostCode FROM tblstaff st, tblBranch br WHERE st.BranchNo = br.BranchNo

-- SELECT staffNo,FName,Designation,Salary,br.BranchNo,PostCode,Street FROM tblstaff st, tblBranch br WHERE st.BranchNo='B005' AND st.BranchNo = br.BranchNo

-- SELECT staffNo,LName,FName,Designation,Salary,br.BranchNo,PostCode FROM tblstaff st, tblBranch br WHERE StaffNo LIKE 'SG%' AND st.BranchNo = br.BranchNo

-- Create table Schedule
-- (
-- City varchar(15),
-- StartTime varchar(15),
-- EndTime varchar(15)
-- );
-- INSERT INTO schedule VALUES
-- ('London','8:00 AM','5:00 PM'),
-- ('Glasglow','7:00 AM','4:00 PM'),
-- ('Bristol','9:00 AM','6:00 PM'),
-- ('Aberdeen','10:00 AM','9:00 PM');

-- Create table Schedule1
-- (
-- BranchNo varchar(15),
-- StartTime varchar(15),
-- EndTime varchar(15)
-- );
-- INSERT INTO Schedule1 VALUES
-- ('B003','8:00 AM','5:00 PM'),
-- ('B004','7:00 AM','4:00 PM'),
-- ('B005','9:00 AM','6:00 PM'),
-- ('B007','10:00 AM','9:00 PM');

-- SELECT * FROM schedule
-- SELECT * FROM schedule1

-- SELECT BranchNo,Street,branch.City,PostCode,StartTime,EndTime FROM branch, schedule WHERE branch.City = schedule.City

-- SELECT StaffNo, LName,FName, staff.BranchNo,StartTime,EndTime FROM staff, schedule1 WHERE staff.BranchNo = schedule1.BranchNo

-- 28.) Joining 3 Tables
-- SELECT StaffNo, LName, FName, staff.BranchNo, branch.City, StartTime,EndTime FROM staff, branch, schedule WHERE staff.branchno = branch.branchno AND branch.city = schedule.city

-- SELECT
-- staffNo,LName,FName,Sex,Designation,staff.Brancho,City,PostCode,StartTime,EndTime FROM staff, branch, schedule1 WHERE staff.Brancho = branch.BranchNo AND branch.BranchNo = schedule1.BranchNo

-- SELECT staffNo, FName, LName, st.BranchNo, Stree,City,PostCode FROM staff st, branch br WHERE st.BranchNo = 'B007' AND st.BranchNo = br.BranchNo

-- SELECT staffNo, FName, LName, st.BranchNo, Stree,City,PostCode FROM staff st, branch br WHERE st.BranchNo = 'B003' AND st.BranchNo = br.BranchNo ORDER BY LName ASC

-- 29.) Deleting Specific records.
-- USE db_initials_matthew
-- SELECT * FROM tblstaff

-- DELETE FROM tblstaff WHERE staffNo = 'SG14'

-- DELETE FROM tblstaff WHERE salary = 9000

-- DELETE FROM tblstaff WHERE LName LIKE '%e%'

-- 30.) Editing Record in the table
-- UPDATE tblstaff SET Salary = 30000 WHERE StaffNo='SG5'

-- USE db_pre_mp1_initials_matthew
-- SELECT * FROM tblStudinfo 
-- SELECT * FROM tblStudinfo WHERE Course='BSIT' >> (3 Records)

-- UPDATE tblstudinfo SET Subject='IT101' WHERE Course = 'BSIT'
-- SELECT * FROM tblstudinfo WHERE FGrade < 74

-- UPDATE tblstudinfo SET FGrade = 75 WHERE FGrade < 74
-- UPDATE tblstudinfo SET FGrade = 90, MGrade = 75, FGrade = 99 WHERE StudNo = '001'

-- SELECT * FROM tblstudinfo WHERE StudNo='001'