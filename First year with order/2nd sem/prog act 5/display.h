
int display_record(){
	int choice = 0;
	display_header1();//will display this ==== display records === 
	if(total_record == 0){
		cout<<"\tNo records to display.\n\n";
		cout<<"\tDo you want to add records now?\n";
		cout<<"\t\tPress 1 - YES\n";
		cout<<"\t\tPress 2 - GO BACK TO MAIN MENU\n";
		cout<<"\t\tPress 3 - CLOSE PROGRAM\n";
		ulit:
		cout<<"\t\t\tINPUT (1-3): ";cin>>choice;
		switch(choice){
			case 1:
				system ("cls"); add_record(); system ("cls");
				return 0;
				break;
			case 2:
				return 0; break;
			case 3:
				return 1; break;
			default:
				cout<<"\t\t\tINVALID INPUT.";
				goto ulit;
		}
	}
	display_header2(); //will display the gp and netpay only titles
	for(int i = 0; i <50; i++){
		if(employee[i].id == 0){
			continue;
		}
		display(i);//will display the data
	}
	footer_display(total_record);
	cout<<"Press any key to continue...";
	getch();
}

void display_header1(){
	int w = 90;
	cout<<"======================================================================================================================================================================\n";
	cout<<setw(w)<<" DISPLAY RECORDS\n";
	cout<<"======================================================================================================================================================================\n";
}

void display_header2(){
	int w=22;
	cout<<"EMPLOYEE ID";
	cout<<setw(w)<<"LAST NAME";
	cout<<setw(w)<<"FIRST NAME";
	cout<<setw(w)<<"MIDDLE NAME";
	cout<<setw(w)<<"RANK";
	cout<<setw(w+11)<<"GROSS SALARY";
	cout<<setw(w+4)<<"NET SALARY"<<endl;
}

void display(int a){
	int w = 25;
	cout<<employee[a].id;
	cout<<setw(w)<<employee[a].last_name;
	cout<<setw(w)<<employee[a].first_name;
	cout<<setw(w)<<employee[a].middle_name;
	cout<<setw(w+2)<<employee[a].rank;
	cout<<setw(w)<<employee[a].grosspay;
	cout<<setw(w)<<employee[a].netpay<<endl;
}
void super_display(int a){
	cout<<"\n\tEMPLOYEE DETAILS\n";
	cout<<"\t------------------------------------------\n";
	cout<<"\tEMPLOYEE ID: "<<employee[a].id<<endl;
	cout<<"\tEMPLOYEE NAME: "<<employee[a].last_name<<", "<<employee[a].first_name<<" "<<employee[a].middle_name<<endl;
	cout<<"\tEMPLOYEE RANK: "<<employee[a].rank<<endl;
	cout<<"\tSALARY\n";
	cout<<"\t\tGROSS PAY: "<<employee[a].grosspay<<endl;
	cout<<"\t\tDEDUCTIONS:\n";
	cout<<"\t\t\tPhil.Health: "<<employee[a].phil_health<<endl;
	cout<<"\t\t\tHDMF: "<<employee[a].HDMF<<endl;
	cout<<"\t\t\tTAX: "<<employee[a].tax<<endl;
	cout<<"\t\t\tLOAN: "<<employee[a].loan<<endl;
	cout<<"\t\tNET PAY: "<<employee[a].netpay<<endl;
	cout<<"\t------------------------------------------\n\n\n";
}
void footer_display(int number){
	cout<<"======================================================================================================================================================================\n";
	cout<<setw(150)<<"TOTAL NUMBER OF RECORDS: "<<number<<"\n\n";
}
