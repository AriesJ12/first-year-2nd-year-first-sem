#include <iostream>
using namespace std;

void powerXY(){
	double base, answer = 1;
	int power;
	cout<<"input BASE: ";cin>> base;
	cout<<"input POWER: ";cin>> power;
	for(int i = 1; i<= power; i++){
		answer *= base;
	}
	cout<<base<<" raised to the power of "<< power<<" is "<<answer;
}
