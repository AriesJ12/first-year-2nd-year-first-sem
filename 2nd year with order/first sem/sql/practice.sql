drop database if exists grp1;
create database grp1;

Use grp1;

Create table information( -- combine table of admin and user

    I_id int not null auto_increment,
    email varchar(50),
    password varchar(50),
    accountType boolean, -- TRUE for user FALSE for admin
    FName varchar(50),
    LName varchar(50),
    sex varchar(20),
    address varchar(50),
    day varchar(15),
    month varchar(15),
    year varchar(15),
    primary key (I_id)
);

insert into information (email, password, accountType,
FName, LName, sex, address, day, month, year) values ("hide@gmail.com", "1234", true,  "aries",
"tagle", "male", "san juan", "12", "December","2001"),
("gelo@gmail.com", "1234", true,  "gelo",
"gelo", "male", "san juan", "12", "December","2001"),
("gab@gmail.com", "1234", false,  "aries",
"tagle", "male", "san juan", "12", "December","2001")
;


select * from information;

-- Create table audit_trail (
-- 	atID int not null auto_increment,
-- 	loginTime varchar(50),
--     I_id int,
--     Primary key (atID),
--     Foreign key (I_id) references information(I_id)
-- );

-- insert into audit_trail() values (1, "wala", 1);


-- select*from audit_trail;


create table books (
	ISBN int not null,
    title varchar(50),
    url varchar(255),
    Description text,
    price float,
    genre varchar(50),
    recommended boolean, -- true if reco false if not
    quantity int,
	Primary key (ISBN)
);

insert into books () values (123, "classroom of the elite",
"https://you-zitsu.fandom.com/wiki/You-Zitsu_Wiki",
"a boy genius comes to school to dominate it" ,"500.50","events, horror", true,50);

insert into books () values (124, "boss",
"https://www.vox.com/culture/2017/3/29/15071760/boss-baby-review-alec-baldwin-donald-trump", 
"a boy genius comes to school" ,"350.50","events, horror", false,50);


insert into books () values (125, "ugly",
"https://www.redbubble.com/i/poster/The-Fuck-You-Looking-At-Funny-Blobfish-Deep-Sea-Fish-by-BornDesign/44437156.E40HW",
 "a girl" ,"200.50","events, horror", false,50);
select * from books;

create table transaction (
	tran_id int not null auto_increment,
    ISBN int not null,
    I_id int not null,
    Quan_ordered int default 0,
    dateANDtime varchar(50) default "Not bought",
    confirm boolean default false, -- checks if customer is really gonna buy it
    pickedUP boolean default false, -- true for nakuha na false for hindi
    Primary key (tran_id),
    foreign key (ISBN) references books(ISBN)
    on delete cascade,
    foreign key (I_id) references information(I_id)
);


select*from transaction;

create table auditing (
	audit_id int not null auto_increment,
    I_id int,
    Time varchar(50),
    Status varchar(50),
	primary key (audit_id),
    foreign key (I_id) references information (I_id)
);

select * from auditing;

create table smtp (
	id int not null default 1,
	eme varchar(50),
	sapp varchar(50),
    primary key (id)
);

insert into smtp (eme, sapp) 

values("airamgabriel.iskolar@gmail.com","jyqw bcym bbkp fgwo");

select*from smtp;


create table bill(
	bill_id int default 0 not null,
    I_id int not null,
    grandtotal float,
    dateANDtime varchar(50),
    primary key (bill_id),
    foreign key (I_id) references information (i_id)
);

select* from bill;
