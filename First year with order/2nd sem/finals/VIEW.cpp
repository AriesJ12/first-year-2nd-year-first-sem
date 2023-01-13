#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include <string>

using namespace std;

int main(){
	ifstream read;
	string data;//stores the data to be extracted
	read.open("Order.txt");
	if (read == NULL){//will check if Order.txt exist
		cout<<"No saved record for orders\n";
	}else{
		while(!read.eof()){
			getline(read, data);
			cout<<data<<endl;
		}
		cout<<"ALL RECORDS HAS BEEN DISPLAYED\n";
	}
	read.close();
	cout<<"Press any key...";
	getch();
	system("cls");
	system("MAIN.exe");
	return 0;
}
