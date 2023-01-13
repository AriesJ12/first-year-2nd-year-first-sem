#include <iostream>
#include <cstring>

using namespace std;

int main() {//didnt work
	string str1 = "blue", str2 = "red";
	cout<<str1<<endl<<str2<<endl;
	strcpy(str1, str2);
	cout<<str1<<endl<<str2<<endl;

	return 0;
}
