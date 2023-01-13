#include <iostream>
#include <cstring>

/*using namespace std;

int main() {
	char str[50];
	char ch;
	char *found;
	cout<<"input a string: "; cin.getline(str, 50);
	cout<<"input a char to be searched: "; cin>>ch;
	found = strchr(str, tolower(ch));
	if(found){
		cout<<"its here";
	}
	else{
		cout<<"not here";
	}
	return 0;
}*/
using namespace std;

int main() {
  	char quote[] = "Remember me when you look at the moon!";

  // break the string when it encounters empty space
	char* word = strtok(quote, " ");

	while(word != NULL ){
		cout <<  word<<endl;
		word = strtok('\0', " ");
		
	}
	cout<< " here"<<word;
	

  return 0;
}

// Output: Remember
