#include <iostream>
using namespace std;

int main() {
	int Row, Column;
	cout<<"How many row? ";cin>>Row;
	cout<<"How many column? ";cin>>Column;
	int table[Row][Column], Rsum[Row], Csum[Column];
	cout<<"======================================================="<<endl;
	cout<<"Input "<<Row*Column<<" numbers: "<<endl;
	for(int a = 0; a < Row; a++){//input
		for(int i = 0; i < Column; i++){
			cin>>table[a][i];
		}
	}
	cout<<"======================================================="<<endl;
	for(int a = 0; a < Row; a++){//output
		Rsum[a]=0; //for some reason the initial value is not 0 so i have to declare it
		for(int i = 0; i < Column; i++){
			cout<<table[a][i]<<"\t";
			Rsum[a] += table[a][i];
			if(a == 0){
				Csum[i] = 0;
			}
			Csum[i] += table[a][i];
		}
		cout<<"||\t"<<Rsum[a];//sum row
		cout<<endl;
	}
	cout<<"======================================================="<<endl;
	for(int a = 0; a < Column; a++){//sum column
		cout<<Csum[a]<<"\t";
	}
	return 0;
}
