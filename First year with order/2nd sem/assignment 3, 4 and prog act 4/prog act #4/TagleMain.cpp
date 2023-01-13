#include "menu.h"
#include "arithmetic.h"
#include "ave.h"
#include "multi.h"
#include "power.h"
#include <cstdlib>
int main(){
	MainMenu:
	int M;
	M = MENU();
	switch(M){
		case 1: addition(); break;
		case 2: difference(); break;
		case 3: product(); break;
		case 4: quotient(); break;
		case 5: average(); break;
		case 6: multiple(); break;
		case 7: powerXY(); break;
		case 8:
			cout<<"==========================================================\n";
			cout<<"Program has been terminated.\n";
			cout<<"Press any key to exit...";
			return 0;
	}
	cout<<"\n\nPress 1 to go back to MAIN MENU\n";
	cout<<"Press 2 to EXIT program\n";
	AGAIN:
	cout<<"Press 1 or 2: "; cin>>M;
	if(M==1){
		system("cls");
		goto MainMenu;
	}
	else if(M==2){
		cout<<"==========================================================\n";
		cout<<"Program has been terminated.\n";
		cout<<"Press any key to exit...";
		return 0;
	}
	else{
		cout<<"Invalid input. ";
		goto AGAIN;
	}
}

