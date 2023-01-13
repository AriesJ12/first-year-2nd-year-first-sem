#include <iostream>

using namespace std;
const int MAX = 3;

int main(){
/*	char letters[3];
	letters[0] = 'c';
	letters[1] = 'b';
	letters[2] = 'a';
	
	char* ptrletter;
	ptrletter = letters;
/*	char* ptrletter[3];
	for(int i = 0; i<3;i++){
		ptrletter[i] = &letters[i];
	}
	char** pptrletter[3];
	for(int i = 0; i < 3; i++){
		pptrletter[i] = ptrletter[i];
	}
	
	for(int i = 0; i<3;i++){
		cout<< ptrletter<<endl;
		ptrletter++;
	}*/
	
//	int letters[MAX] = {3,1,2};
	int letters = 3;
	int *ptrletter;
	ptrletter = &letters;
	cout<<ptrletter;
/*	for(int i = 0; i<3;i++){
		cout<< ptrletter<<endl;
		ptrletter++;
	}*/
	
	return 0;
}
