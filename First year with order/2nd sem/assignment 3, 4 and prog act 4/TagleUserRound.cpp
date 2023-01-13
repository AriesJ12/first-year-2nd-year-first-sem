#include <iostream>
using namespace std;

int rounding(double x);

int main(){
	double UserInput;
	cout<< "Input a number with decimal point: "; cin>>UserInput;
	cout<< "Rounding it off to whole number: " << rounding(UserInput);
	return 0;
}

int rounding(double x){
	int ans;
	double check;
	ans = x;
	check = x - ans;
	if(check >= 0.5){
		ans++;
	}
	return ans;
}
