#include <iostream>
using namespace std;

int GetAve(int x, int y, int z);
double GetAve(double x, double y, double z);

int main(){
	GetAve(20, 60, 100);
	GetAve(2.41, 3.333, 12.25);
	int x,y,z;
	cout<<"x = "; cin>>x;
	cout<<"y = "; cin>>y;
	cout<<"z = "; cin>>z;
	GetAve(x,y,z);
	float a,b,c;
	cout<<"a = "; cin>>a;
	cout<<"b = "; cin>>b;
	cout<<"c = "; cin>>c;
	GetAve(a,b,c);
	double u,v,w;
	cout<<"u = "; cin>>u;
	cout<<"v = "; cin>>v;
	cout<<"w = "; cin>>w;
	GetAve(u,v,w);
}

int GetAve(int x, int y, int z){
	int Ave = (x+y+z)/3;
	cout<< "Average of "<< x <<", "<<y <<", and " <<z<<" is "<< Ave<<endl<<endl;
}
double GetAve(double x, double y, double z){
	double Ave = (x+y+z)/3;
	cout<< "Average of "<< x <<", "<<y <<", and " <<z<<" is "<< Ave<<endl<<endl;
}
