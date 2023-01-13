#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

int main(){
	cout<<"-=* Welcome to MAMA MIA RESTAURANT *=-\n";
	cout<<"__________________________________________________________________________________________\n";
	//display choices
	cout<<"1 - Input Order\n";
	cout<<"2 - View Sales\n";
	cout<<"3 - Close the Program\n";
	cout<<"__________________________________________________________________________________________\n";
	//getting input
	CHOOSE:
	cout<<"Input 1, 2 or 3: "; int choice; cin>>choice;
	switch(choice){
		case 1:{//goes to add
			system ("cls");
			system ("ADD.exe");
			break;
		}
		case 2:{//goes to view
			system ("cls");
			system ("VIEW.exe");
			break;
		}
		case 3:{//closes the program
			system ("cls");
			cout<<"\nClosing Time... Have a great day!\n";
			cout<<"Press any key...";
			getch();
			return 0;
		}
		default:{//goes to add
			cout<<"INVALID INPUT. ";
			goto CHOOSE;
		}
	}
}
