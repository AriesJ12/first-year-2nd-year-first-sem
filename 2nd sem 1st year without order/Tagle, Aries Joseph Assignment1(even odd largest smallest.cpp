#include <iostream>

using namespace std;

int main() {
    int InputNumber, Checker, e=0, d=0, Largest, Smallest;
    cout<<"How many numbers do you want to enter? ";
    cin>> InputNumber;
    cout<<endl<<"Input "<<InputNumber<<" numbers."<<endl;
    cout<<"================== "<<endl;
    int Input[InputNumber], Even[InputNumber], Odd[InputNumber];
    for(int i = 0; i < InputNumber ;i++){
        cout<<i+1<<": ";
        cin>>Input[i];
        Checker = Input[i] % 2;
        if(Checker == 0){
            Even[e]=Input[i];
            e++;
        }
        else{
            Odd[d]=Input[i];
            d++;
        }
    }
    Largest = Input[0];
    Smallest = Input[0];
    for (int i=1; i<InputNumber ; i++){
        if(Largest < Input[i]){
            Largest = Input[i];
        }
        if(Smallest > Input[i]){
            Smallest = Input[i];
        }
    }
    cout<<endl<<"You have entered "<<e<<" EVEN numbers."<<endl;
    for(int i = 0; i < e; i++){
        cout<<i+1<<": "<<Even[i]<<endl;
    }
    cout<<endl<<"You have entered "<<d<<" ODD numbers."<<endl;
    for(int i = 0; i < d; i++){
        cout<<i+1<<": "<<Odd[i]<<endl;
    }
    cout<<"The LARGEST number you entered is: "<<Largest<<endl;
    cout<<"The SMALLEST number you entered is: "<<Smallest<<endl;
    return 0;
}
