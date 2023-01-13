#include <iostream>

using namespace std;

int main() {
string LastName, FirstName;
int YearLvl, Mathematics, Science, English, Filipino, Computer, error=0;
cout<< "Last Name: ";getline(cin, LastName);
cout<< "First Name: "; getline(cin, FirstName);
/*I know getline hasn't been taught to us yet, but I have to use it in this case.
the problem with cin is that when getting string variable value it doesnt accept space. So I hope you consider this
I also wanted to use just cin with the LastName but apparently the First name variable wouldnt work - u can try it on your own*/
do{
	cout<< "Year Level: "; cin>>YearLvl;
	if(error == 2 && (YearLvl>=5 || YearLvl<=0)){
	cout<< "Program will be terminated due to multiple invalid inputs.";
	return 0;
	}
	else if(YearLvl>=5 || YearLvl<=0){
		cout<<"Invalid Input. ";
		error++;
	}
}while(YearLvl>=5 || YearLvl<=0);
error=0;
cout<< "Input Grade:"<< endl;
do{
	cout<< "\tMathematics: "; cin>>Mathematics;
	if(error == 2 && (Mathematics >= 101 || Mathematics<=64)){
	cout<< "Program will be terminated due to multiple invalid inputs.";
	return 0;
	}
	else if(Mathematics >= 101 || Mathematics<=64){
		cout<<"Invalid Input. ";
		error++;
	}
}while(Mathematics >= 101 || Mathematics<=64);
error=0;
do{
	cout<< "\tScience: "; cin>>Science;
	if(error == 2 && (Science >= 101 || Science<=64)){
	cout<< "Program will be terminated due to multiple invalid inputs.";
	return 0;
	}
	else if(Science >= 101 || Science<=64){
		cout<<"Invalid Input. ";
		error++;
	}
}while(Science >= 101 || Science<=64);
error=0;
do{
	cout<< "\tEnglish: "; cin>>English;
	if(error == 2 && (English >= 101 || English<=64)){
	cout<< "Program will be terminated due to multiple invalid inputs.";
	return 0;
	}
	else if(English >= 101 || English<=64){
		cout<<"Invalid Input. ";
		error++;
	}
}while(English >= 101 || English<=64);
error=0;
do{
	cout<< "\tFilipino: "; cin>>Filipino;
	if(error == 2 && (Filipino >= 101 || Filipino<=64)){
	cout<< "Program will be terminated due to multiple invalid inputs.";
	return 0;
	}
	else if(Filipino >= 101 || Filipino<=64){
		cout<<"Invalid Input. ";
		error++;
	}
}while(Filipino >= 101 || Filipino<=64);
error=0;
do{
	cout<< "\tComputer: "; cin>>Computer;
	if(error == 2 && (Computer >= 101 || Computer<=64)){
	cout<< "Program will be terminated due to multiple invalid inputs.";
	return 0;
	}
	else if(Computer >= 101 || Computer<=64){
		cout<<"Invalid Input. ";
		error++;
	}
}while(Computer >= 101 || Computer<=64);
error=0;

int Average = (Mathematics + Science + English + Filipino + Computer) / 5;
cout<< "Average: "<<Average<<endl;
switch (Average){
    case 65 ... 74:
        cout<<"Remark: Poor";
        break;
    case 75 ... 79:
        cout<<"Remark: Fair";
        break;
    case 80 ... 89:
        cout<<"Remark: Good";
        break;
    case 90 ... 99:
        cout<<"Remark: Very Good";
        break;
    case 100:
        cout<<"Remark: Excellent";
        break;
}
return 0;
}
