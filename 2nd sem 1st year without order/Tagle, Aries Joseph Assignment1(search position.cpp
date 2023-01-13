#include <iostream>

using namespace std;

int main() {
    int InputNumber, SearchNumber, NumberPosition=0;
    cout<<"How many numbers do you want to input? ";
    cin>> InputNumber ;
    int Input[InputNumber], PositionSearch[InputNumber];
    for(int i = 0; i < InputNumber ;i++){
        cout<< "number " << i+1 <<": ";
        cin>>Input[i];
    }
    cout<<"Input the number you want to search: ";
    cin>> SearchNumber;
    for(int i = 0; i < InputNumber ; i++){
        if(SearchNumber == Input[i]){
            PositionSearch[NumberPosition] = i+1;
            NumberPosition++;
            
        }
    }
    if(NumberPosition != 0){
        for(int i = 0; i< NumberPosition; i++){
        	cout<< SearchNumber<< " found at position "<<PositionSearch[i]<<endl;
        }
    }
   else{
       cout<< SearchNumber<< " is not on the list you entered.";
   }
    return 0;
}
