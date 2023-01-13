#include <iostream>
using namespace std;

void addition(){
	int InputN;
	double sum=0, UserInput;
	cout<<"===================== ADDITION ========================\n";
	cout<<"How many numbers do you want to input? ";cin>> InputN;
	for(int i = 1; i <= InputN; i++){
		cout<< i<< ": "; cin>>UserInput;
		sum += UserInput;
	}
	cout<< "The sum of the "<< InputN<< " numbers you entered is "<<sum;
}
void difference(){
	int InputN;
	double difference=0, UserInput;
	cout<<"===================== SUBTRACTION ========================\n";
	cout<<"How many numbers do you want to input? ";cin>> InputN;
	for(int i = 1; i <= InputN; i++){
		cout<< i<< ": "; cin>>UserInput;
		if(i == 1){
			difference = UserInput;
			continue;
		}
		difference -= UserInput;
	}
	cout<< "The difference of the "<< InputN<< " numbers you entered is "<<difference;
}
void product(){
	int InputN;
	double product=1, UserInput;
	cout<<"===================== MULTIPLICATION ========================\n";
	cout<<"How many numbers do you want to input? ";cin>> InputN;
	for(int i = 1; i <= InputN; i++){
		cout<< i<< ": "; cin>>UserInput;
		product *= UserInput;
	}
	cout<< "The product of the "<< InputN<< " numbers you entered is "<<product;
}
void quotient(){
	int InputN;
	double quotient=1, UserInput;
	cout<<"===================== DIVISION ========================\n";
	cout<<"How many numbers do you want to input? ";cin>> InputN;
	for(int i = 1; i <= InputN; i++){
		cout<< i<< ": "; cin>>UserInput;
		if(i == 1){
			quotient = UserInput;
			continue;
		}
		quotient /= UserInput;
	}
	cout<< "The quotient of the "<< InputN<< " numbers you entered is "<<quotient;
}
