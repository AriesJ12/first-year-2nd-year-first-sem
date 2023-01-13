#include <iostream>
#include <string>
using namespace std;

class phrase {
public:
	string unencrypt;
	string encrypt;
	
	phrase(string aUnencrypt) {
		unencrypt = aUnencrypt;
	}
	string encryption(int size) {
		char letters[27] = "abcdefghijklmnopqrstuvwxyz";
		int eNumber[size];
		for (int i = 0; i < size; i++) {//loop convert the unencrypt text to a number;parent loop
			for (int a = 0; a <= 25; a++) {
				if (unencrypt[i] == letters[a]) {
					eNumber[i] = a + 3;
				}
			}
			if(eNumber[i]>= 26){
				eNumber[i] -= 26;
			}
			encrypt += letters[eNumber[i]];
		}
		return encrypt;
	}
};

int main()
{
	string phr;
	cout << "type the phrase: "; cin >> phr;
	phrase first(phr);
	int haba = phr.length() ;//finds the number of times we will loop
	cout<< first.encryption(haba);
}
