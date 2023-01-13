#include <iostream>
using namespace std;

void average(){
	int InputN;
	double average=0, UserInput;
	cout<<"===================== GET AVERAGE ========================\n";
	cout<<"How many numbers do you want to input? ";cin>> InputN;
	for(int i = 1; i <= InputN; i++){
		cout<< i<< ": "; cin>>UserInput;
		average += UserInput;
	}
	average /= InputN;
	cout<< "The average of the "<< InputN<< " numbers you entered is "<<average;
}
