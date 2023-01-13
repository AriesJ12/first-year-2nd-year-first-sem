
void add_record(){
	int w = 40;//width
	int record;//how many records to input
	int eID;
	cout<<"===================================================================\n";
	cout<<setw(w)<<" ADD RECORDS\n";
	cout<<"===================================================================\n";
	cout<<"How many records do you want to add? "; cin>>record;
	if(record < 0){
		cout<<"===================================================================\n";
		cout<<"Invalid Input, returning to main menu\n";
		cout<<"press any key to continue";
		getch();
		return;
	}
	int a = 1;//keeping track of how many records has been added
	for(int i = record_number; i<record_number+record; i++){
		system ("cls");
		cout<<"===================================================================\n";
		cout<<setw(w)<<" ADD RECORDS\n";
		cout<<"===================================================================\n";
		cout<<setw(w)<<"Adding record of "<<a++<<" of "<<record<<endl<<endl;
		add_again:
		cout<<"INPUT EMPLOYEE ID: "; cin>>eID;
		if (found_record(eID, i)){
			cout<<"\tINVALID INPUT. ";
			goto add_again;
		}else{
			employee[i].id = eID;
		}
		cin.ignore();
		cout<<"INPUT LAST NAME: "; cin.getline(employee[i].last_name,50);
		cout<<"INPUT FIRST NAME: "; cin.getline(employee[i].first_name,50);
		cout<<"INPUT MIDDLE NAME: "; cin.getline(employee[i].middle_name,50);
		cout<<"EMPLOYEE RANK\n";
		cout<<"\t1 - Instructor\n";
		cout<<"\t2 - Assistant Professor\n";
		cout<<"\t3 - Associate Professor\n";
		cout<<"\t4 - Professor\n";
		AGAIN:
		cout<<"\tINPUT EMPLOYEE RANK(1-4): "; cin>> employee[i].number_rank;
		switch(employee[i].number_rank){
			case 1: strcpy(employee[i].rank, "Instructor"); employee[i].grosspay = 30000; break;
			case 2: strcpy(employee[i].rank, "Assistant Professor"); employee[i].grosspay = 50000; break;
			case 3: strcpy(employee[i].rank, "Associate Professor"); employee[i].grosspay = 100000; break;
			case 4: strcpy(employee[i].rank, "Professor"); employee[i].grosspay = 200000; break;
			default:
				cout<<"\tINVALID INPUT.";
				goto AGAIN;
		}
		cout<<"EMPLOYEE RANK: "<<employee[i].rank<<endl;
		cout<<"\tINPUT EMPLOYEE LOAN: "; cin>> employee[i].loan;
		employee[i].HDMF = 100;
		employee[i].tax = employee[i].grosspay * 0.25;
		employee[i].phil_health = employee[i].grosspay * 0.04;
		employee[i].netpay = employee[i].grosspay - employee[i].phil_health - employee[i].tax - employee[i].HDMF - employee[i].loan;
	}
	record_number+=record;
	total_record = record_number - deleted_record;
	cout<<"===================================================================\n";
	cout<<setw(30)<<record<<" RECORD(S) WAS SUCCESSFULLY ADDED\n\n";
	cout<<"Press any key to continue...";
	getch();
}
