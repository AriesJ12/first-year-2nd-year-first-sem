#include <iostream>
#include <iomanip>
#include <cstdlib>
#include<cstring>
#include "conio.h"
#include "class.h"
#include "menu.h"
using namespace std;
//so many functions wahahahaha
Employee employee[50];
int record_number;// keeps track kung ilang na ung narecord
int deleted_record;//keeps track of how many are deleted
int total_record;//keeps track of how many record are there
void add_record(); //place in add record.h
int display_record(); //display ALL records with - placed in display.h
void super_display(int a);//display with extra steps xD
void footer_display(int number);
void display(int a);//will display ASKED data records;(will be use in update delete and search) - placed in display.h
void display_header1();//will display === display record === place in display. h
void display_header2();//will display the title upto gp and np - place in display.h
void update_record(); 
void delete_record();
void search_record();
bool found_record(int number, int record); //taga hanap ng id - ginamit ito sa search delete update and add -place in add record.h
int found_record(int id);//returns where in the array
bool LN_checker(char name[50]);
bool FN_checker(char name[50]);
bool MN_checker(char name[50]);
bool rank_checker(int rank);

int main(){
	employee[0].id = 0;
	record_number = 0;
	deleted_record = 0;
	total_record = record_number - deleted_record;
	MainMenu:
	int M;
	int close;
	M = MENU();
	switch(M){
		case 1:
			system ("cls");
			close = display_record(); 
			if(close == 1){
				system ("cls");
				cout<<"\nProgram has been terminated.\n";
				cout<<"Press any key to continue...\n";
				getch();
				return 0;
			}else{
				break;
			}
		case 2:
			system ("cls"); add_record(); break;
		case 3:	
			system ("cls"); update_record(); break;
			break;
		case 4:
			system ("cls"); delete_record(); break;
			break;
		case 5:
			system ("cls"); search_record(); break;
			break;
		case 6:
			system ("cls");
			cout<<"\nProgram has been terminated.\n";
			cout<<"Press any key to continue...\n";
			getch();
			return 0;
	}
	system ("cls");
	goto MainMenu;
}
//nasa baba itong mga to, kasi nag eerror kapag nasa taas(nakalagay kasi sila bago ma declare ung global variable na employee
#include "add record.h"
#include "display.h"
#include "search.h"
#include "update.h"
#include "delete.h"
