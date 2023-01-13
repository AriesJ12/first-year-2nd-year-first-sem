#include <iostream>
#include <cstring>

using namespace std;
int main() {
	char the_word[] = "programming", user_guess[] = "-----------", user_answer, user_reserve[50];
	char answered_letter[50];
	int max_fail = 5, user_mistake = 0, N_guess= 0;
	do{
		letter_again:
			cout<<"Guess a letter("<<max_fail - user_mistake<<" mistakes and you're out): "<<user_guess;
			cout<<endl<<"the clue is: its a very hard task that is needed by the computer to function: ";
			cin>>user_answer;
			for(int a = 0; a <= N_guess; a++){
				if(user_answer == answered_letter[a]){
					cout<<"\nYou already answered/inputted this letter\n\n";
					goto letter_again;
				}
			}
			answered_letter[N_guess] = user_answer;
			N_guess++;
			strcpy(user_reserve, user_guess);
			for(int i = 0; i < strlen(the_word); i++){
				if(the_word[i] == tolower(user_answer)){
					user_guess[i] = user_answer;
				}
			}
			if(strcmp(user_guess, user_reserve) == 0){
				user_mistake++;
			}
			if(user_mistake == max_fail){
				cout<<"\n\nOoof, you have reached the maximum amount of mistakes: GAME OVER ;-;";
				return 0;
		}
			
	}while(strcmpi(the_word, user_guess)!= 0);
	
	cout<<"Congratulations!! You have guessed the right word: "<<the_word;
	
	return 0;
	
}
