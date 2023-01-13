#include <iostream>
#include <string>

using namespace std;

int main() {
	string name_team1, name_team2, winning_team[4];
	int wins_team1, wins_team2, score_team1, score_team2;
	for(int i = 0; i < 4; i++){
		cout<<"GAME "<<i+1<<endl;
		cout<<"Input Team 1 name: ";getline(cin, name_team1);
		cout<<"Input Team 2 name: ";getline(cin, name_team2);
		wins_team1=0;
		wins_team2=0;
//		cin.ignore();
		for(int a = 1; a <= 4; a++){
			if(a == 4){
				if(wins_team2 != wins_team1){
					break;
				}
				else{
					cout<<"\nTeam "<<name_team1<<": "<<wins_team1<<"WIN(S)"<<endl;
					cout<<"Team "<<name_team2<<": "<<wins_team2<<"WIN(S)"<<endl;
					cout<<"\nTeam "<<name_team1<<" and Team "<<name_team2<<" will have ROUND 4"<<endl;
					cout<<"The first team to get 10 points is the winner."<<endl;
				}
			}
			cout<<endl<<"Round "<<a<<":\n";
			cout<<"\tTeam "<<name_team1<<" Points: "; cin>>score_team1;
			cout<<"\tTeam "<<name_team2<<" Points: "; cin>>score_team2;
			cout<<"\t__________________________\n";
			if(score_team1 > score_team2){
				cout<<"\tWinner: Team "<<name_team1<<endl;
				wins_team1++;
			}
			else if(score_team1 < score_team2){
				cout<<"\tWinner: Team "<<name_team2<<endl;
				wins_team2++;
			}
			else{
				cout<<"\tNO WINNER"<<endl;
			}

		}
		cout<<"\nTeam "<<name_team1<<": "<<wins_team1<<"WIN(S)"<<endl;
		cout<<"Team "<<name_team2<<": "<<wins_team2<<"WIN(S)"<<endl;
		cout<<endl<<"GAME "<<i+1<<" WINNER: Team ";
		if(wins_team1 > wins_team2){
			cout<<name_team1;
			winning_team[i] = name_team1;
		}
		else{
			cout<<name_team2;
			winning_team[i] = name_team2;
		}
		cout<<"\n\n==========================================================\n"<<endl;
		cin.ignore();
	}
	cout<<"\tSUMMARY OF WINNERS: "<<endl;
	for (int i = 0; i<4; i++){
		cout<<"\t\t Game "<<i+1<<": "<<winning_team[i]<<endl;
	}
	return 0;
}
