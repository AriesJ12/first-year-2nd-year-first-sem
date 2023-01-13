#include <iostream>
using namespace std;

int MENU(){
	int UserChoice;
	cout<<"===================== MAIN MENU ========================\n";
	cout<<"What function do you want to perform?\n";
	cout<<"1 - ADDITION\n";
	cout<<"2 - SUBTRACTION\n";
	cout<<"3 - MULTIPLICATION\n";
	cout<<"4 - DIVISION\n";
	cout<<"5 - GET AVERAGE\n";
	cout<<"6 - 100 MULTIPLES OF A NUMBER\n";
	cout<<"7 - POWER OF A NUMBER\n";
	cout<<"8 - EXIT\n";
	cout<<"========================================================\n";
	cout<< "Press 1 to 8: "; cin>> UserChoice;
	return UserChoice;
}
