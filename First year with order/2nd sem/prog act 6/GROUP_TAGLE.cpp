#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <string>

using namespace std;

int main(){
	int w = 30;
	int choice;//for case
	ifstream read;//to read
	ofstream write;//to create and write
	char display[50];//helps ifstream in reading
	char first_name[50];//declared first name, last name, and file name here because its gonna be useful in case 1 and 3
	char last_name[50];
	char file_name[50];
	AGAIN:
	cout<<"======================================================================================================================\n\n";
	cout<<"CREATE PAYSLIP?\n";
	cout<<"1 - YES\n";
	cout<<"2 - DISPLAY PAYROLL\n";
	cout<<"3 - DISPLAY PAYSLIP\n";
	cout<<"... or enter any key to END PROGRAM\n";
	cout<<"======================================================================================================================\n\n";
	cout<<"Input 1,2 or 3: "; cin>>choice; cin.ignore();
	switch(choice){
		case 1:{
			system("cls");
			bool wrong = false;
			char position[50];
			int number;//employee number
			double basic_pay;
			int position_num;
			double deductions = 0;//save the total deductions;
			double phil, HDMF, insurance, tax, savings, loan, net_pay;
			cout<<"This program is designed to create payslip\n\n";
			cout<<"======================================================================================================================\n\n";
			cout<<"INPUT EMPLOYEE NUMBER: "; cin>>number; cin.ignore();//gets employee number, firstname,lastname,and position
			cout<<"INPUT EMPLOYEE FIRST NAME: "; cin.getline(first_name, 50);
			cout<<"INPUT EMPLOYEE LAST NAME: "; cin.getline(last_name, 50);
			do{//do one time employee position then checks if wrong
				if(wrong){
					cout<<"Invalid Input. ";
				}//gets position, below
				cout<<"SELECT EMPLOYEE POSITION\n";
				cout<<"\t1 - Manager\n";
				cout<<"\t2 - Assistant Level 2\n";
				cout<<"\t3 - Assistant Level 1\n";
				cout<<"\t4 - Clerk Level 2\n";
				cout<<"\t5 - Clerk Level 1\n";
				cout<<"\t6 - Receptionist\n";
				cout<<"\t7 - Security Officer\n";
				cout<<"\t8 - Utility Officer\n";
				cout<<"Input (1-8): "; cin>>position_num; cin.ignore();
				wrong = true;
			}while(position_num > 8 || position_num < 1);
			wrong = false;
			switch(position_num){
				case 1: strcpy(position, "Manager"); basic_pay = 50000; break;//saves position, text
				case 2: strcpy(position, "Assistant Lvl 2"); basic_pay = 30000; break;
				case 3: strcpy(position, "Assistant Lvl 1"); basic_pay = 25000; break;
				case 4: strcpy(position, "Clerk Lvl 2"); basic_pay = 20000; break;
				case 5: strcpy(position, "Clerk Lvl 1"); basic_pay = 18000; break;
				case 6: strcpy(position, "Receptionist"); basic_pay = 15000; break;
				case 7: strcpy(position, "Security Officer"); basic_pay = 12500; break;
				case 8: strcpy(position, "Utility Officer"); basic_pay = 10000; break;
			}
			cout<<"======================================================================================================================\n\n";
			cout<<"DEDUCTIONS:"<<endl;//display the deductions; gets phil health, hdmf, insurance, tax, saving, and loan
			
			phil = basic_pay * 0.012;//gets phil, same as the next ones but diff scenarios
			deductions += phil;//save the deduction same as the next ones
			cout<<setw(w)<<"Phil. Health:"<<setw(w)<<phil<<endl; //display and save in the file = same applies below
			HDMF = 100;
			deductions += HDMF;
			cout<<setw(w)<<"HDMF:"<<setw(w)<<100<<endl; 
			insurance = basic_pay * 0.02;
			deductions += insurance;
			cout<<setw(w)<<"Insurance:"<<setw(w)<<insurance<<endl; 
			if(basic_pay < 25000){//if basic pay is below or equal to 25,000 -> 0 tax
				tax = 0;
				cout<<setw(w)<<"Tax:"<<setw(w)<<tax<<endl;
			}else{
				tax = basic_pay * 0.025;
				deductions += tax;
				cout<<setw(w)<<"Tax:"<<setw(w)<<tax<<endl; 
			}
			savings = (basic_pay-deductions) * 0.05;
			deductions += savings;
			cout<<setw(w)<<"Coop. Savings:"<<setw(w)<<savings<<endl; 
			cout<<setw(w+1)<<"INPUT Coop. Loan: ";cin>>loan; cin.ignore(); //gets loan
			deductions += loan;
			cout<<"======================================================================================================================\n\n";
			cout<<"SUMMARY:\n";//display basic pay, deductions and net pay
			cout<<setw(w)<<"Basic Pay:"<<setw(w)<<basic_pay<<endl;//display 
			cout<<setw(w)<<"Total Deductions:"<<setw(w)<<deductions<<endl;
			net_pay = basic_pay - deductions;
			cout<<setw(w)<<"NET PAY:"<<setw(w)<<net_pay<<endl; 
			//===========================================================================//creating and saving data in file
			strcpy(file_name, last_name);//creating the file name and the file(TO WRITE)
			strcat(file_name, "_");
			strcat(file_name, first_name);
			strcat(file_name, ".txt");
			write.open(file_name);//file name created and written
			write <<number <<endl<< first_name<<endl<<last_name<<endl;//saves employee number, first name and last name
			write << position <<endl<<phil<<endl<<HDMF<<endl;//saves position, phil and hdmf
			write << insurance<<endl<<tax<<endl<<savings<<endl<<loan<<endl;//saves insurance, tax, savings, and loan
			write << basic_pay<<endl<<deductions<<endl<<net_pay; //saves basic_pay, deductions, and net_pay
			write.close();
			write.open("PAYROLL.txt", ios::app);//payroll being created/written
			write <<number <<endl<< first_name<<endl<<last_name<<endl;//saves employee number, first name and last name
			write << position <<endl<<phil<<endl<<HDMF<<endl;//saves position, phil and hdmf
			write << insurance<<endl<<tax<<endl<<savings<<endl<<loan<<endl;//saves insurance, tax, savings, and loan
			write << basic_pay<<endl<<deductions<<endl<<net_pay<<endl<<"!"<<endl; //saves basic_pay, deductions, and net_pay
			//i used ! as a seperator(delimiter)
			write.close();
			cout<<"======================================================================================================================\n\n";
			//code below will display that you have created the file and saved the data
			cout<<"PAYSLIP for "<<first_name<<" "<<last_name<<" has been created.\n";
			cout<<first_name<<" "<<last_name<<" was included in PAYROLL file.\n";
			cout<<"======================================================================================================================\n\n\n\n";
			goto AGAIN;
		}
			
		case 2:{
			system("cls");
			cout<<"COMPANY ROLL\n";//code below will display payroll(all pay slips)
			cout<<"======================================================================================================================\n\n";
			read.open("PAYROLL.txt");
			if(read == NULL){//will check if payroll exist
				cout<<"\nNo PAYROLL file created yet.\n\n\n";
			}else{
				while(!read.eof()){
					read.getline(display, 50);
					if(strcmpi(display, "!") == 0||strcmpi(display,"")==0){//delimeter - will end line
						cout<<endl;
					}else{
						cout<<display<<"\t";//will display 
					}
				}	
			}
			read.close();
			goto AGAIN;
		}
			
		case 3:{
			system("cls");
			int count = 0;//needed because of array stored.
			string store[13];//using string cause its easier to use compare to char - you only have to display 13 datas
			cout<<"DISPLAY PAYSLIP\n";//will full display an INDIVIDUAL PAYSLIP
			cout<<"======================================================================================================================\n\n";
			//code below will get the file name
			cout<<"Type Employee LAST NAME: ";cin.getline(last_name,50);
			cout<<"Type Employee FIRST NAME: ";cin.getline(first_name,50);
			strcpy(file_name, last_name);//getting and opening the file name to READ
			strcat(file_name, "_");
			strcat(file_name, first_name);
			strcat(file_name, ".txt");
			read.open(file_name);
			cout<<"======================================================================================================================\n\n";
			if(read == NULL){//will check if the payslip indiv exist
				cout<<file_name<<" does not exists.\n\n";
			}else{
				while(!read.eof()){//gets the data
					getline(read, store[count]);
					count++;
				}
				cout<<"EMPLOYEE NUMBER: "<<store[0]<<endl;//displays the data
				cout<<"EMPLOYEE FIRST NAME: "<<store[1]<<endl;
				cout<<"EMPLOYEE LAST NAME: "<<store[2]<<endl;
				cout<<"EMPLOYEE POSITION: "<<store[3]<<endl<<endl;
				cout<<"DEDUCTIONS\n";
				cout<<"\tPHIL.HEALTH: "<< store[4]<<endl;
				cout<<"\tHDMF: "<< store[5]<<endl;
				cout<<"\tINSURANCE: "<< store[6]<<endl;
				cout<<"\tTAX: "<< store[7]<<endl;
				cout<<"\tCOOP. SAVINGS: "<< store[8]<<endl;
				cout<<"\tCOOP LOAN: "<< store[9]<<endl;
				cout<<"SUMMARY\n";
				cout<<"\tBASIC PAY: "<< store[10]<<endl;
				cout<<"\tTOTAL DEDUCTIONS: "<< store[11]<<endl;
				cout<<"\tNET PAY: "<< store[12]<<endl<<endl;
			}
			read.close();
			goto AGAIN;
		}
		default: {
			cout<<"PROGRAM HAS BEEN TERMINATED\n";
			system("pause"); return 0;
		}
			
	}
	
}
