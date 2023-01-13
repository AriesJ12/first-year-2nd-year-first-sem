#include <iostream>
using namespace std;
	
int main(){
	int Row, Column;
	cout<<"How many row? ";cin>>Row;
	cout<<"How many column? ";cin>>Column;
	int table[Row][Column], transpose[Column][Row], reserve[Column*Row], _1d=0;
	cout<<"======================================================="<<endl;
	cout<<"Input "<<Row*Column<<" numbers: "<<endl;
	for(int a = 0; a < Row; a++){//input
		for(int i = 0; i < Column; i++){
			cin>>table[a][i];
			reserve[_1d] = table[a][i];
			_1d++;
		}
	}
	cout<<"======================================================="<<endl;
	cout<<Row<<"x"<<Column<<" Matrix"<<endl;
	for(int a = 0; a < Row; a++){//output 1
		for(int i = 0; i < Column; i++){
			cout<<table[a][i]<<"\t";
		}
		cout<<endl;
	}
	cout<<"======================================================="<<endl;
	cout<<Column<<"x"<<Row<<" Matrix (Transposition)"<<endl;
	_1d = 0;
	for(int a = 0; a < Column; a++){//input 2
		for(int i = 0; i < Row; i++){
			transpose[a][i] = reserve[_1d];
			_1d++;
		}
	}
	for(int a = 0; a < Column; a++){//output 2
		for(int i = 0; i < Row; i++){
			cout<<transpose[a][i]<<"\t";
		}
		cout<<endl;
	}		
return 0;
}

