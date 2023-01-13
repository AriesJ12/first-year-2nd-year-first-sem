#include <iostream>
#include <iomanip>
using namespace std;

int MENU(){
	int UserChoice;
	int w = 30;
	cout<<"========================================================\n";
	cout<<setw(w)<<" MAIN MENU\n";
	cout<<"========================================================\n";
	cout<<"\t1 - DISPLAY RECORDS\n";
	cout<<"\t2 - ADD RECORDS\n";
	cout<<"\t3 - UPDATE RECORDS\n";
	cout<<"\t4 - DELETE RECORDS\n";
	cout<<"\t5 - SEARCH RECORDS\n";
	cout<<"\t6 - CLOSE PROGRAM\n";
	cout<<"========================================================\n";
	cout<< "Press 1 to 6: "; cin>> UserChoice;
	while(UserChoice < 1 || UserChoice > 6){
		cout<< "\tINVALID INPUT. Press 1 to 6: "; cin>> UserChoice;
	}
	return UserChoice;
}
