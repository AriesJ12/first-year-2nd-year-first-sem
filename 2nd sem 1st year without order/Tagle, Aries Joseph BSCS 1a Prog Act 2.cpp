#include <iostream>
using namespace std;

int main() {
	//computing grades and ranking them
	int studentNum;
	cout<<"How many students do you want to input? "; cin>>studentNum;
	double studentGrd[studentNum][4], studentAverage[studentNum], reserve;
	int studentNo[studentNum], studentRes;
	for(int i = 0; i<studentNum; i++){
		studentAverage[i] = 0;//I have to declare it to 0 because for some reason it bugs(sometimes)
		cout<<endl<<"Input Average Grade of student #"<<i+1<<endl;
		for(int a = 0; a<4; a++){//getting input
			switch (a){
				case 0: cout<<"\tFirst "; break;
				case 1: cout<<"\tSecond "; break;
				case 2: cout<<"\tThird "; break;
				case 3: cout<<"\tFourth "; break;
			}
			cout<<"Grading Period: ";cin>>studentGrd[i][a];
			while(studentGrd[i][a] < 65 || studentGrd[i][a] > 100){
				cout<<"\t\tINVALID INPUT. Input again: ";cin>>studentGrd[i][a];
			}
			studentAverage[i] += studentGrd[i][a];	
		}
		studentAverage[i] /= 4; studentNo[i] = i+1;
		cout<<"\t================================"<<endl;
		cout<<"\tAverage of Student #"<<i+1<<": "<<studentAverage[i]<<endl<<endl;
	}
	
	cout<<"STUDENT RANKING:"<<endl;//ranking
	cout<<"================================================"<<endl;
	cout<<"Rank\tStudent NO:\tAverage"<<endl;
	for(int i = 0; i<studentNum; i++){
		for(int b = i+1; b<studentNum; b++){
			if(studentAverage[i] < studentAverage[b]){
				reserve = studentAverage[i];
				studentAverage[i] = studentAverage[b];
				studentAverage[b] = reserve;
				studentRes = studentNo[i];
				studentNo[i] = studentNo[b]; 
				studentNo[b] = studentRes; 
			}
		}
		cout<<i+1<<"\t"<<studentNo[i]<<"\t\t"<<studentAverage[i]<<endl;
	}

	return 0;
}
