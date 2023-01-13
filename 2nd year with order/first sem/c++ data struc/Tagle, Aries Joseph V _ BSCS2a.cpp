#include <iostream>
#include <stack>
#include <string>
using namespace std;


int main (){
    int FinalAnswer= 9000;//final answer
    stack<int> UserAnswer;//history of user answers
    int answer;
    cout<<"guess the number: ";
    do{
    	cin >> answer;
    	UserAnswer.push(answer);
    	if(UserAnswer.top() < FinalAnswer){
    		cout << "Your answer should be higher\n";
		} else if(UserAnswer.top() > FinalAnswer){
			cout << "Your answer should be lesser\n";
		}
	}while (UserAnswer.top() != 9000);
	cout<<"you win\n";
	cout<<"You have "<<UserAnswer.size()<<" attempts\n";
	cout<<"your history is, starting from the most recent is: \n";
	while (!UserAnswer.empty()){
		cout<<UserAnswer.top()<<endl;
		UserAnswer.pop();
	}
}
