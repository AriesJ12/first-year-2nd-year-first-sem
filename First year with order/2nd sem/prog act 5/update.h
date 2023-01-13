void update_record(){
	int w = 40;
	int eID;//temp store of id to be inputted and compared to
	int eRank;//temp store for rank
	int array_place;
	int choice;//place holder for choice in numbering
	bool wrong = false;//checks if the input is in range
	cout<<"==================================================================\n";
	cout<<setw(w)<<" UPDATE RECORDS\n";
	cout<<"==================================================================\n";
	if(total_record == 0){
		cout<<"\t No record to update.\n\n";
		cout<<"Press any to continue...";
		getch();
		return;
	}
	cout<<"Input Employee ID to UPDATE: ";cin>>eID;
	if(eID == 0){
		cout<<"The Input is RESERVED. Going Back to main menu";
		cout<<"\n\nPress any key to continue...";
		getch();
		return;
	}
	if(found_record(eID, record_number)){
		array_place = found_record(eID);
		cout<<"Do you want to UPDATE record of "<<employee[array_place].last_name<<", "
		<<employee[array_place].first_name<<" "<<employee[array_place].middle_name<<"?\n";
		cout<<"\tInput 1 - YES\n";
		cout<<"\tInput 2 - GO BACK TO MAIN MENU\n";
		do{
			if(wrong){
				cout<<"INVALID INPUT. ";
			}
			cout<<"Press 1 or 2: ";cin>>choice;
			wrong = true;
		}while(choice > 2 || choice < 1);
		wrong = false;
		if(choice == 1){
			cout<<"Choose what you want to update\n";
			cout<<"1 - LAST NAME\n";
			cout<<"2 - FIRST NAME\n";
			cout<<"3 - MIDDLE NAME\n";
			cout<<"4 - EMPLOYEE RANK\n";
			cout<<"5 - LOAN\n";
			do{
				if(wrong){
					cout<<"\tINVALID INPUT.";
				}
				cout<<"\tInput 1 to 5: ";cin>>choice;
				wrong =true;
			}while(choice > 5 || choice < 1);
			wrong = false;
			switch(choice){
				case 1:
					cin.ignore();
					cout<<"UPDATE LAST NAME: ";cin.getline(employee[array_place].last_name, 50);
					break;
				case 2:
					cin.ignore();
					cout<<"UPDATE FIRST NAME: ";cin.getline(employee[array_place].first_name, 50);
					break;
				case 3:
					cin.ignore();
					cout<<"UPDATE MIDDLE NAME: ";cin.getline(employee[array_place].middle_name, 50);
					break;
				case 4://dito hanggang pababa ung salary change
					cout<<"1 - Instructor\n";
					cout<<"2 - Assistant Professor\n";
					cout<<"3 - Associate Professor\n";
					cout<<"4 - Professor\n";
					do{
						if(wrong){
							cout<<"INVALID INPUT.";
						}
						cout<<"UPDATE EMPLOYEE RANK: ";cin>>eRank;
						wrong = true;
					}while (eRank > 4 || eRank <1);
					wrong = false;
					employee[array_place].number_rank = eRank;
					switch(employee[array_place].number_rank){
						case 1: strcpy(employee[array_place].rank, "Instructor"); employee[array_place].grosspay = 30000; break;
						case 2: strcpy(employee[array_place].rank, "Assistant Professor"); employee[array_place].grosspay = 50000; break;
						case 3: strcpy(employee[array_place].rank, "Associate Professor"); employee[array_place].grosspay = 100000; break;
						case 4: strcpy(employee[array_place].rank, "Professor"); employee[array_place].grosspay = 200000; break;
					}employee[array_place].tax = employee[array_place].grosspay * 0.25;//recomputing the net pay
					employee[array_place].phil_health = employee[array_place].grosspay * 0.04;
					employee[array_place].netpay = employee[array_place].grosspay - employee[array_place].phil_health 
					- employee[array_place].tax - employee[array_place].HDMF - employee[array_place].loan;
					cout<<"Employee Rank change to ''"<<employee[array_place].rank<<"''\n";
					break;
				case 5:
					cout<<"UPDATE LOAN: ";cin>>employee[array_place].loan;
					employee[array_place].netpay = employee[array_place].grosspay //reupdating net pay
					- employee[array_place].phil_health - employee[array_place].tax - employee[array_place].HDMF - employee[array_place].loan;
					break;
			}
			cout<<"==================================================================\n\n";
			cout<<"Record of ''"<<employee[array_place].last_name<<", "
			<<employee[array_place].first_name<<" "<<employee[array_place].middle_name<<
			"'' has been UPDATED successfully.\n";
			cout<<"==================================================================\n\n";
		}else{
			cout<<"Press any key to continue...";
			getch();
			return;
		}
	}else{
		cout<<"==================================================================\n";
		cout<<setw(w)<<eID<<" does not exist in the record\n";
		cout<<setw(w)<<"\t\tNO RECORD HAS BEEN UPDATED\n";
	}
	cout<<"Press any key to continue...";
	getch();
	return;
}
