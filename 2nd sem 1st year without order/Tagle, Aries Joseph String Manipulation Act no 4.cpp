#include <iostream>
#include <string>
//Tagle, Aries Joseph V. - String Manipulation no 4
using namespace std;

int main() {
	string name;
	cout<<"Input name: ";getline(cin, name);
	int length = name.length();
	for(int i = 0; i < length; i++){
		switch (tolower(name[i])){
			case 'a':
				name[i] = '@';
				break;
			case 'e':
				name[i] = '^';
				break;
			case 'i':
				name[i] = '!';
				break;
			case 'o':
				name[i] = '*';
				break;
			case 'u':
				name[i] = '$';
				break;
		}
	}
	cout<<"Encrypted name: "<<name;
	return 0;
}
