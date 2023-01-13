drop database if exists grp2;
create database grp2;

Use grp2;

Create table Account_compile(
	account_id int not null auto_increment,
    information_id int,
    email varchar(50),
    password varchar(50),
    accountType boolean, -- TRUE for user FALSE for admin
    primary key (account_id),
    foreign key (information_id) references information
);

Create table information (
	information_id int not null auto_increment,
	FName varchar(50),
    LName varchar(50),
    sex varchar(20),
    address varchar(50),
    day varchar(15),
    month varchar(15),
    year varchar(15),
    primary key (information_id)
);

Create table user ();

Create table admin();
