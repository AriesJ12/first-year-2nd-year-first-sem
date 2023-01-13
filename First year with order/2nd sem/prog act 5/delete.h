void delete_record(){
	int w = 40;
	int eID;//temp store of id to be inputted and compared to
	int eRank;//temp store for rank
	int array_place;
	int choice;//place holder for choice in numbering
	bool wrong = false;//checks if the input is in range
	cout<<"==================================================================\n";
	cout<<setw(w)<<" DELETE RECORDS\n";
	cout<<"==================================================================\n";
	if(total_record == 0){
		cout<<"\t No record to delete.\n\n";
		cout<<"Press any to continue...";
		getch();
		return;
	}
	cout<<"Input Employee ID to DELETE: ";cin>>eID;
	if(eID == 0){
		cout<<"The Input is RESERVED. Going Back to main menu";
		cout<<"\n\nPress any key to continue...";
		getch();
		return;
	}
	if(found_record(eID, record_number)){
		array_place = found_record(eID);
		cout<<"Do you want to DELETE record of "<<employee[array_place].last_name<<", "
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
			cout<<"\nRecord of ''"<<employee[array_place].last_name<<", "
			<<employee[array_place].first_name<<" "<<employee[array_place].middle_name<<
			"'' has been DELETED successfully.\n";
			cout<<"==================================================================\n\n\n";
			deleted_record++;
			total_record = record_number - deleted_record;
			employee[array_place].id = 0;
			strcpy(employee[array_place].last_name, "");
			strcpy(employee[array_place].first_name, "");
			strcpy(employee[array_place].middle_name, "");
			employee[array_place].number_rank = 0;
			strcpy(employee[array_place].rank, "");
			employee[array_place].grosspay = 0;
			employee[array_place].phil_health = 0;
			employee[array_place].tax = 0;
			employee[array_place].HDMF = 0;
			employee[array_place].loan = 0;
			employee[array_place].netpay = 0;
		}else{
			cout<<"Press any key to continue...";
			getch();
			return;
		}
	}else{
		cout<<"==================================================================\n";
		cout<<setw(w)<<eID<<" does not exist in the record\n";
		cout<<setw(w)<<"\t\tNO RECORD HAS BEEN DELETED\n\n";
	}
	cout<<"Press any key to continue...";
	getch();
	return;
}
