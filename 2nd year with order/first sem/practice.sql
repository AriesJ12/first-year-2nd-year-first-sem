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
FName, LName, sex, address, day, month, year) 

values ("admin@gmail.com", "1234", false, "Airam",
"Aguilar", "male", "New York", "7", "September","2003"),
("gelo@gmail.com", "1234", true, "gelo",
"gelo", "male", "san juan", "12", "December","2001"),
("hide@gmail.com", "1234", true, "aries",
"tagle", "male", "san juan", "12", "December","2001")
;


select * from information;



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

insert into books () values (1642751375, "Classroom of the Elite",
"https://books.google.com.ph/books/about/Classroom_of_the_Elite_Manga_Vol_1.html?id=zIFeEAAAQBAJ&printsec=frontcover&source=kp_read_button&hl=en&redir_esc=y#v=onepage&q&f=false",
"The cutthroat school drama light novels that inspired an anime! Students of the prestigious Tokyo Metropolitan Advanced Nurturing High School are given remarkable freedom—if they can win, barter, or save enough points to work their way up the ranks! Ayanokouji Kiyotaka has landed at the bottom in the scorned Class D, where he meets Horikita Suzune, who’s determined to rise up the ladder to Class A. Can they beat the system in a school where cutthroat competition is the name of the game?" ,
"500.50","Suspense, Psychological thriller, Light Novel", true,50);

insert into books () values (1481469819, "Baby Boss",
"https://books.google.com.ph/books/about/The_Boss_Baby.html?id=O38RaiFZEKEC&printsec=frontcover&source=kp_read_button&hl=en&redir_esc=y#v=onepage&q&f=false", 
"The boss baby is used to getting his way—drinks made to order 24/7, a private jet, and meetings around the clock. But when his demands aren’t getting proper responses, he has to go to new lengths to achieve the attention he deserves." ,
"350.50","Adventure, Fantasy, Comedy, Children's Book", false,50);


insert into books () values (0425287777, "Ugly",
"https://books.google.com.ph/books/about/Ugly.html?id=8PwlCwAAQBAJ&printsec=frontcover&source=kp_read_button&hl=en&redir_esc=y#v=onepage&q&f=false",
 "When Robert Hoge was born, he had a tumor the size of a tennis ball in the middle of his face and short, twisted legs. Surgeons removed the tumor and made him a new nose from one of his toes.  Amazingly, he survived—with a face that would never be the same. " ,
 "200.50","Children's Book", false,50);
 
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
    ON DELETE CASCADE,
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
    foreign key (I_id) references information(I_id)
);

select* from bill;
