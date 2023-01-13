#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(){
	fstream create;
	char title[50];
	int number;
	create.open("tagle.txt", ios::out);
		cout<<"input your text: "; cin>>number;
		create <<"ako"<<endl<<"ako";
	create.close();
	create.open("tagle.txt", ios::in);
		while(!create.eof()){
			create.getline(title, 50);
			cout<<title<<endl;
		}
	create.close();
	return 0;
}
