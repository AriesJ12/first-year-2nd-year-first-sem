#include <iostream>
#include <cstring>

using namespace std;
int main() {
	char country[50];
	cout<< "COUNTRY NAME: "; cin.getline(country, 50);
	if (stricmp(country, "brunei")==0) {
		cout<<"CAPITAL: Bandar Seri Begawan";
	}
	else if (stricmp(country, "cambodia")==0) {
		cout<<"CAPITAL: Phnom Penh";
	}
	else if (stricmp(country, "east timor")==0) {
		cout<<"CAPITAL: Dili";
	}
	else if (stricmp(country, "indonesia")==0) {
		cout<<"CAPITAL: Jakarta";
	}
	else if (stricmp(country, "laos")==0) {
		cout<<"CAPITAL: Vientiane";
	}
	else if (stricmp(country, "Malaysia")==0) {
		cout<<"CAPITAL: Kuala Lumpur";
	}
	else if (stricmp(country, "myanmar")==0) {
		cout<<"CAPITAL: Nay Pyi Daw";
	}
	else if (stricmp(country, "philippines")==0) {
		cout<<"CAPITAL: Manila";
	}
	else if (stricmp(country, "singapore")==0) {
		cout<<"CAPITAL: Singapore";
	}
	else if (stricmp(country, "thailand")==0) {
		cout<<"CAPITAL: Bangkok";
	}
	else if (stricmp(country, "vietnam")==0) {
		cout<<"CAPITAL: Hanoi";
	}
	else {
		cout<<country<<" is not a South East Asian Country";
	}
	

	return 0;
}
