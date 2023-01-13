#include <iostream>
#include <cstring>

using namespace std;
int main() {
	char input[50], reverse[50];
	cout<<"Enter a word: "; cin>>input;//i used cin>> because its not a phrase
	strcpy(reverse, input);
	strrev(reverse);
	int compare = stricmp(reverse, input);
	if (compare == 0){
		cout<<"THE WORD IS A PALINDROME";
	}
	else{
		cout<<"THE WORD IS NOT A PALINDROME";
	}
	return 0;
}
