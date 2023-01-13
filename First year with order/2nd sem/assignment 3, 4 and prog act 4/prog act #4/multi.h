#include <iostream>
using namespace std;

void multiple(){
	double UserInput;
	int multiple = 1;
	cout<<"===================== MULTIPLES OF A NUMBER ========================\n";
	cout<<"Input a Number: ";cin>> UserInput;
	cout<<"\t\tThese are the first 100 multiples of "<<UserInput<<endl;
	for(int i = 1; i <= 10; i++){
		for(int a = 1; a <= 10; a++){
			cout<< UserInput * multiple<< "\t";
			multiple++;
		}
		cout<<endl;
	}
}
