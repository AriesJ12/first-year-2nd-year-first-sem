void search_record(){
	int w = 30;
	int choice;//variable for choosing how to choose
	int choice_view;
	bool wrong = false;
	int eNumber;//temporary holder of employee.id and rank
	int eID;//second holder of employee id to search from
	char eName[50];//temporary holder of ln, fn, mn
	int array_place;//will store where in the array is the ID searched
	int track = 0;//will track how many rank and names in array are found
	cout<<"========================================================\n";
	cout<<setw(w)<<" SEARCH RECORDS\n";
	cout<<"========================================================\n";
	if(total_record == 0){
		cout<<"\tNo record to search.\n\n";
		cout<<"Press any key to continue...";
		getch();
		return;
	}
	cout<<"SEARCH USING\n";
	cout<<"\t1 - Employee ID\n";
	cout<<"\t2 - Last Name\n";
	cout<<"\t3 - First Name\n";
	cout<<"\t4 - Middle Name\n";
	cout<<"\t5 - Employee Rank\n";
	pinaulit://goto
	cout<<"\tINPUT 1-5: ";cin>>choice;
	switch(choice){
		case 1: 
			cout<<"Input EMPLOYEE ID to SEARCH: ";cin>>eNumber;
			if(found_record(eNumber, record_number)){
				display_header1();
				display_header2();
				for(int i = 0; i<record_number ;i++){
					if(eNumber == employee[i].id){
						display(i);
						array_place = i;
						track++;
					}
				}
				footer_display(track);
				cout<<"======================================================================================================================================================================\n";
			}else{
				cout<<"\tEmployee ID ''"<<eNumber<<"'' is not in the record\n\n";
				cout<<"Press any key to continue...";
				getch();
				return;
			}
			break;
		case 2://last name
			cin.ignore();
			cout<<"Input LAST NAME to SEARCH: ";cin.getline(eName, 50);
			if(LN_checker(eName)){//checks first if the name is in there
				display_header1();//have an if in above to see whether we need to display it or not
				display_header2();//this comment is the same with case 3 and 4
				for(int i = 0; i<record_number ;i++){
					if(strcmpi(employee[i].last_name, eName) == 0){
						display(i);
						track++;
					}
				}
				footer_display(track);
				cout<<"======================================================================================================================================================================\n";
			}else{
				cout<<"\tThe LAST NAME ''"<<eName<<"'' is not in the record\n\n";
				cout<<"Press any key to continue...";
				getch();
				return;
			}
			break;
		case 3://first name
			cin.ignore();
			cout<<"Input FIRST NAME to SEARCH: ";cin.getline(eName, 50);
			if(FN_checker(eName)){
				display_header1();
				display_header2();
				for(int i = 0; i<record_number ;i++){
					if(strcmpi(employee[i].first_name, eName) == 0){
						display(i);
						track++;
					}
				}
				footer_display(track);
				cout<<"======================================================================================================================================================================\n";
			}else{
				cout<<"\tThe FIRST NAME ''"<<eName<<"'' is not in the record\n\n";
				cout<<"Press any key to continue...";
				getch();
				return;
			}
			break;
		case 4://middle name
			cin.ignore();
			cout<<"Input MIDDLE NAME to SEARCH: ";cin.getline(eName, 50);
			if(MN_checker(eName)){
				display_header1();
				display_header2();
				for(int i = 0; i<record_number ;i++){
					if(strcmpi(employee[i].middle_name, eName) == 0){
						display(i);
						track++;
					}
				}
				footer_display(track);
				cout<<"======================================================================================================================================================================\n";
			}else{
				cout<<"\tThe MIDDLE NAME ''"<<eName<<"'' is not in the record\n\n";
				cout<<"Press any key to continue...";
				getch();
				return;
			}
			break;
		case 5:
			cout<<"Select from 1 -4\n";
			cout<<"\t1 - Instructor\n";
			cout<<"\t2 - Assistant Professor\n";
			cout<<"\t3 - Associate Professor\n";
			cout<<"\t4 - Professor\n";
			do{
				if(wrong){
					cout<<"\tINVALID INPUT. ";
				}
				cout<<"Input 1-4: ";cin>>eNumber;
				wrong = true;
			}while(eNumber > 4 || eNumber < 1);
			wrong = false;
			if(rank_checker(eNumber)){
				display_header1();
				display_header2();
				for(int i = 0; i<record_number ;i++){
					if(eNumber == employee[i].number_rank){
						display(i);
						track++;
					}
				}
				footer_display(track);
				cout<<"======================================================================================================================================================================\n";
			}else{
				cout<<"\n\tEmployee RANK ''"<<eNumber<<"'' is not in the record\n\n";
				cout<<"Press any key to continue...";
				getch();
				return;
			}
			break;
		default: 
			cout<<"\tINVALID INPUT.";
			goto pinaulit;//goto
	}
	cout<<"VIEW DETAILS?\n";
	cout<<"\t1 - YES\n";
	cout<<"\t2 - GO BACK TO MAIN MENU\n";
	do{//i did do while instead of goto, andami kasing name
		if(wrong){
			cout<<"\tINVALID INPUT.";
		}
		cout<<"\tINPUT 1 OR 2: "; cin>>choice_view;
		wrong = true;//magiging true na kasi pangalawang beses na magiinput kung uulit
	}while(choice_view>2 || choice_view<1);
	wrong = false;
	switch(choice_view){
		case 1:
			do{
				wrong = false;
				do{
					if(wrong){
						cout<<"\tINCORRECT INPUT. ";
					}
					cout<<"INPUT EMPLOYEE ID FROM THE LIST TO DISPLAY DETAILS: ";cin>>eID;
					wrong = true;
				}while(!found_record(eID,record_number));
				wrong = false;
				switch(choice){
					case 1:
						if(eID == eNumber){
							super_display(array_place);
						}else{
							wrong = true;
							cout<<"\tINCORRECT INPUT. ";
						}
						break;
					case 2://for last name
						//search muna ung UNIQUE ID tapos titignan kung ung id nayon ay kamatch ung name
						array_place = found_record(eID);
						if(strcmpi(employee[found_record(eID)].last_name, eName) == 0){
							super_display(found_record(eID));
						}else{
							wrong = true;
							cout<<"\tINCORRECT INPUT. ";
						}
						break;
					case 3://for first name
						array_place = found_record(eID);
						if(strcmpi(employee[found_record(eID)].first_name, eName) == 0){
							super_display(found_record(eID));
						}else{
							wrong = true;
							cout<<"\tINCORRECT INPUT. ";
						}
						break;
					case 4://for middle name
						array_place = found_record(eID);
						if(strcmpi(employee[array_place].middle_name, eName) == 0){
							super_display(array_place);
						}else{
							wrong = true;
							cout<<"\tINCORRECT INPUT. ";
						}
						break;
					case 5:
						array_place = found_record(eID);
						if(employee[array_place].number_rank == eNumber){
							super_display(array_place);
						}else{
							wrong = true;
							cout<<"\tINCORRECT INPUT. ";
						}
						break;
				}
			}while(wrong);
		case 2:
			cout<<"Press any key to continue...";
			getch();
			return;
	}
	wrong = false;
	cout<<"Press any key to continue...";
	getch();
}

bool found_record(int id, int record){//id checker
	for(int i = 0; i < record; i++){//first parameter is what it is to compare to
		if(id == employee[i].id){//second parameter is how many numbers is the record
			return true;
		}
	}
	return false;
}
int found_record(int id){
	for(int i = 0; i < record_number; i++){//first parameter is what it is to compare to
		if(id == employee[i].id){//second parameter is how many numbers is the record
			return i;
		}
	}
}

bool LN_checker(char name[50]){//checks the record if it has the last name
	for(int i = 0; i < record_number; i++){//first parameter is what it is to compare to
		if(strcmpi(name ,employee[i].last_name)==0) {//second parameter is how many numbers is the record
			return true;
		}
	}
	return false;
}
bool FN_checker(char name[50]){//checks the record if it has the first name
	for(int i = 0; i < record_number; i++){//first parameter is what it is to compare to
		if(strcmpi(name ,employee[i].first_name)==0) {//second parameter is how many numbers is the record
			return true;
		}
	}
	return false;
}
bool MN_checker(char name[50]){//checks the record if it has the middle name
	for(int i = 0; i < record_number; i++){//first parameter is what it is to compare to
		if(strcmpi(name ,employee[i].middle_name)==0) {
			return true;
		}
	}
	return false;
}

bool rank_checker(int rank){//checks the record if it has the rank
	for(int i = 0; i < record_number; i++){//first parameter is what it is to compare to
		if(rank == employee[i].number_rank){
			return true;
		}
	}
	return false;
}


