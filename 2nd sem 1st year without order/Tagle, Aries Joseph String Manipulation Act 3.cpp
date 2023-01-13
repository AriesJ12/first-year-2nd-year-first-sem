#include <iostream>
#include <cstring>

using namespace std;

int main() {
	char phrase[50];
	cout<<"Input a word or phrase: ";cin.getline(phrase, 50);
	int length = strlen(phrase), count = 0; 
	for (int i = 0 ; i < length; i++){
		if(phrase[i] == 'a' || phrase[i] == 'e' || phrase[i] == 'i' || phrase[i] == 'o' || phrase[i] == 'u' ){
			count++;
		}
	}
	cout<< "# of vowels: "<<count;
	return 0;
}
