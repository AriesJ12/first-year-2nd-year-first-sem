#include <iostream>
#include <cmath>
using namespace std;

int main(){
	double UserInput;
	cout<< "Input a number with decimal point: "; cin>>UserInput;
	cout<< "Rounding it off to whole number: " << round(UserInput);
	return 0;
}
