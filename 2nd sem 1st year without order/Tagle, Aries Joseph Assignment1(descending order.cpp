#include <iostream>

using namespace std;

int main() {
    int InputNumber, Reserve = 0;
    cout<<"How many numbers do you want to input? ";
    cin>> InputNumber ;
    cout<<"================================= "<<endl;
    int Input[InputNumber];
    for(int i = 0; i < InputNumber ;i++){
        cin>>Input[i];
    }
    cout<<"================================= "<<endl;
    cout<<"\tDESCENDING ORDER\t"<<endl;
    cout<<"================================= "<<endl;
    
    for(int a = 0; a < InputNumber ; a++){
        for(int i = a+1; i < InputNumber ; i++){
           if(Input[a] < Input[i]){
               Reserve = Input[a];
               Input[a] = Input [i];
               Input[i] = Reserve;
           }
        }
        cout<<Input[a]<<endl;
    }

    return 0;
}
