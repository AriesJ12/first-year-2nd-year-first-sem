#include <iostream>
#include <cstring>

using namespace std;

int main() {
	char price_code[]="computers.x", user_input[50], user_again[50];
	char price_value[]="123456789.0", user_value[50];
	char *found;
	start:
		cout<<"Input Code: ";cin.getline(user_input, 50);
		int user_length = strlen(user_input);
		int price_length = strlen(price_code);
		for(int i = 0; i < user_length; i++){
			found = strchr(price_code, tolower(user_input[i]));
			if(!(found != NULL)){
				cout<<"UNABLE TO CONVERT YOUR UNIT";
				goto jump;
			}
			for(int a = 0; a < price_length; a++){
				if(price_code[a] == tolower(user_input[i])){
					user_value[i] = price_value[a];
				}
			}
		}
		user_value[user_length] = '\0';
		cout<<"VALUE: "<<user_value;
		jump:
		cout<<"\n============================\n\n";
		cout<<"INPUT AGAIN? Type YES to input again, type NO to end program: "; cin.getline(user_again, 50);
		if(strcmpi(user_again, "yes") == 0){
			goto start;
		}
		else if(strcmpi(user_again, "no") == 0){
			cout<<"PROGRAM WILL BE TERMINATED";
			return 0;
		}
		else{
			cout<< "Your answer is neither yes or no, silly; do it again"<<endl;
			goto jump;
		}
}
