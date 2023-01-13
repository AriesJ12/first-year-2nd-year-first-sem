#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

struct CUSTOMER{
	string name, address, contact_number; // will store name, address, and contact number
	char time[50];
	int total; //will store the total amount needed to be paid
	string user_codes[100];//will store codes
	int frequency[27];//will store frequency depending on placement
	string orders[27];//permanent storer of menu_user
};

int main(){
	int w = 20;//width(first)
	int x = 28;//width(second)
	bool wrong = false;//will check the codes
	ofstream write;//will save the files
	CUSTOMER customer; 
	cout<<"-=* Welcome to MAMA MIA RESTAURANT *=-\n";
	cout<<"_____________________________________________________________________________________________\n";
	cout<<"ULAM MENU\n";
	cout<<"_____________________________________________________________________________________________\n";
	//displays the menu choices
	cout<<"\tSILOG MEALS\n";
	cout<<setw(w)<<"S1"<<setw(x)<<"Tocilog"<<setw(w)<<"80.00\n"; customer.orders[0] = "80	Tocilog";
	cout<<setw(w)<<"S2"<<setw(x)<<"Tapsilog"<<setw(w)<<"80.00\n"; customer.orders[1] = "80	Tapsilog";
	cout<<setw(w)<<"S3"<<setw(x)<<"Porksilog"<<setw(w)<<"80.00\n"; customer.orders[2] = "80	Porksilog";
	cout<<setw(w)<<"S4"<<setw(x)<<"Chicksilog"<<setw(w)<<"80.00\n"<<endl; customer.orders[3] = "80	Chicksilog";
	cout<<"\tPORK\n";
	cout<<setw(w)<<"P1"<<setw(x)<<"Lechon Kawali"<<setw(w)<<"60.00\n"; customer.orders[4] = "60	Lechon kawali";
	cout<<setw(w)<<"P2"<<setw(x)<<"Sisig with Egg"<<setw(w)<<"60.00\n"; customer.orders[5] = "60	Sisig with Egg";
	cout<<setw(w)<<"P3"<<setw(x)<<"Tokwat Baboy"<<setw(w)<<"60.00\n"; customer.orders[6] = "60	Tokwat Baboy";
	cout<<setw(w)<<"P4"<<setw(x)<<"Fried Liempo"<<setw(w)<<"75.00\n"; customer.orders[7] = "75	Fried Liempo";
	cout<<setw(w)<<"P5"<<setw(x)<<"Dinakdakan"<<setw(w)<<"100.00\n"; customer.orders[8] = "100	Dinakdakan";
	cout<<setw(w)<<"P6"<<setw(x)<<"BBQ"<<setw(w)<<"100.00\n"; customer.orders[9] = "100	BBQ";
	cout<<setw(w)<<"P7"<<setw(x)<<"Bistek"<<setw(w)<<"150.00\n"; customer.orders[10] = "150	Bistek";
	cout<<setw(w)<<"P8"<<setw(x)<<"Sweet and Sour Pork"<<setw(w)<<"150.00\n"<<endl; customer.orders[11] = "150	Sweet and Sour Pork";
	cout<<"\tCHICKEN\n";
	cout<<setw(w)<<"C1"<<setw(x)<<"Fried Chicken"<<setw(w)<<"80.00\n"; customer.orders[12] = "80	Fried Chicken";
	cout<<setw(w)<<"C2"<<setw(x)<<"Fillet"<<setw(w)<<"80.00\n"; customer.orders[13] = "80	Fillet";
	cout<<setw(w)<<"C3"<<setw(x)<<"Bistek"<<setw(w)<<"100.00\n"; customer.orders[14] = "100	Bistek";
	cout<<setw(w)<<"C4"<<setw(x)<<"Cordon Bleu"<<setw(w)<<"120.00\n"; customer.orders[15] = "120	Cordon Bleu";
	cout<<setw(w)<<"C5"<<setw(x)<<"Honey Glazed"<<setw(w)<<"120.00\n"; customer.orders[16] = "120	Honey Glazed";
	cout<<setw(w)<<"C6"<<setw(x)<<"Buffalo Wings"<<setw(w)<<"150.00\n"<<endl; customer.orders[17] = "150	Buffalo Wings";
	cout<<"\tVEGETABLES\n";
	cout<<setw(w)<<"V1"<<setw(x)<<"Fresh Lumpia"<<setw(w)<<"80.00\n"; customer.orders[18] = "80	Fresh Lumpia";
	cout<<setw(w)<<"V2"<<setw(x)<<"Fried Lumpia"<<setw(w)<<"80.00\n"; customer.orders[19] = "80	Fried Lumpia";
	cout<<setw(w)<<"V3"<<setw(x)<<"Chopsuey"<<setw(w)<<"100.00\n"; customer.orders[20] = "100	Chopsuey";
	cout<<setw(w)<<"V4"<<setw(x)<<"Ensalada"<<setw(w)<<"120.00\n"<<endl; customer.orders[21] = "120	Ensalda";
	cout<<"\tDRINKS\n";
	cout<<setw(w)<<"D1"<<setw(x)<<"Gulaman"<<setw(w)<<"50.00\n"; customer.orders[22] = "50	Gulaman";
	cout<<setw(w)<<"D2"<<setw(x)<<"Lemonade"<<setw(w)<<"50.00\n"; customer.orders[23] = "50	Lemonade";
	cout<<setw(w)<<"D3"<<setw(x)<<"Buko Juice"<<setw(w)<<"50.00\n"; customer.orders[24] = "50	Buko Juice";
	cout<<setw(w)<<"D4"<<setw(x)<<"Coke 1.5L"<<setw(w)<<"70.00\n"; customer.orders[25] = "70	Coke 1.5L";
	cout<<setw(w)<<"D5"<<setw(x)<<"Sprite 1.5L"<<setw(w)<<"70.00\n"<<endl; customer.orders[26] = "70	Sprite 1.5L";
	//will get the user info and order
	cout<<"Customer Name: "; getline(cin, customer.name);
	cout<<"Customer Address: "; getline(cin, customer.address);
	cout<<"Customer Contact Number: "; getline(cin, customer.contact_number);
	cout<<"CUSTOMER ORDER\n";
	ORDER:
	int many; //will store how many ULAM is to be ordered
	cout<<"\tHow many ULAM CODES do you want to input?: "; cin>>many; cin.ignore();
	if(many <= 0 ){
		cout<<"You can't be a customer if you dont order anything silly.";
		goto ORDER;
	}
	for(int i = 0; i< many;i++){
		string check_codes;//temporary store for codes to check
		do{
			wrong = false;
			cout<<"ULAM CODE: "; getline(cin, check_codes);
			for(int a = 0; a < check_codes.size(); a++){//will convert the codes into lower cases so it wont be case sensitive
				check_codes[a] = tolower(check_codes[a]);
			}
			//will check codes if its in the system
			if(check_codes == "s1" || check_codes == "s2" || check_codes == "s3" || check_codes == "s4" || check_codes == "p1" || 
			check_codes == "p2" || check_codes == "p3" || check_codes == "p4" || check_codes == "p5" || check_codes == "p6" || 
			check_codes == "p7" || check_codes == "p8" || check_codes == "c1" || check_codes == "c2" || check_codes == "c3" || 
			check_codes == "c4" || check_codes == "c5" || check_codes == "c6" || check_codes == "v1" || check_codes == "v2" || 
			check_codes == "v3" || check_codes == "v4" || check_codes == "d1" || check_codes == "d2" || check_codes == "d3" || 
			check_codes == "d4" || check_codes == "d5"){
				customer.user_codes[i] = check_codes;
			}else{
				wrong = true;
				cout<<"INVALID INPUT. ";
			}
		}while(wrong);
	}
	for(int i = 0; i < 27; i++){//will turn all customer order(unique) frequency to 0 - needed because sometimes the program assign a random number;
		customer.frequency[i] = 0;
	}
	customer.total = 0; //assigning zero to it, cause sometimes the program will assign a random number;
	for(int i = 0; i < many; i++){//getting the frequence and the customer.total
		if(customer.user_codes[i] == "s1"){
			customer.frequency[0]++;
			customer.total += 80;
		}else if(customer.user_codes[i] == "s2"){
			customer.frequency[1]++;
			customer.total += 80;
		}else if(customer.user_codes[i] == "s3"){
			customer.frequency[2]++;
			customer.total += 80;
		}else if(customer.user_codes[i] == "s4"){
			customer.frequency[3]++;
			customer.total += 80;
		}else if(customer.user_codes[i] == "p1"){
			customer.frequency[4]++;
			customer.total += 60;
		}else if(customer.user_codes[i] == "p2"){
			customer.frequency[5]++;
			customer.total += 60;
		}else if(customer.user_codes[i] == "p3"){
			customer.frequency[6]++;
			customer.total += 60;
		}else if(customer.user_codes[i] == "p4"){
			customer.frequency[7]++;
			customer.total += 75;
		}else if(customer.user_codes[i] == "p5"){
			customer.frequency[8]++;
			customer.total += 100;
		}else if(customer.user_codes[i] == "p6"){
			customer.frequency[9]++;
			customer.total += 100;
		}else if(customer.user_codes[i] == "p7"){
			customer.frequency[10]++;
			customer.total += 150;
		}else if(customer.user_codes[i] == "p8"){
			customer.frequency[11]++;
			customer.total += 150;
		}else if(customer.user_codes[i] == "c1"){
			customer.frequency[12]++;
			customer.total += 80;
		}else if(customer.user_codes[i] == "c2"){
			customer.frequency[13]++;
			customer.total += 80;
		}else if(customer.user_codes[i] == "c3"){
			customer.frequency[14]++;
			customer.total += 100;
		}else if(customer.user_codes[i] == "c4"){
			customer.frequency[15]++;
			customer.total += 120;
		}else if(customer.user_codes[i] == "c5"){
			customer.frequency[16]++;
			customer.total += 120;
		}else if(customer.user_codes[i] == "c6"){
			customer.frequency[17]++;
			customer.total += 150;
		}else if(customer.user_codes[i] == "v1"){
			customer.frequency[18]++;
			customer.total += 80;
		}else if(customer.user_codes[i] == "v2"){
			customer.frequency[19]++;
			customer.total += 80;
		}else if(customer.user_codes[i] == "v3"){
			customer.frequency[20]++;
			customer.total += 100;
		}else if(customer.user_codes[i] == "v4"){
			customer.frequency[21]++;
			customer.total += 120;
		}else if(customer.user_codes[i] == "d1"){
			customer.frequency[22]++;
			customer.total += 50;
		}else if(customer.user_codes[i] == "d2"){
			customer.frequency[23]++;
			customer.total += 50;
		}else if(customer.user_codes[i] == "d3"){
			customer.frequency[24]++;
			customer.total += 50;
		}else if(customer.user_codes[i] == "d4"){
			customer.frequency[25]++;
			customer.total += 70;
		}else if(customer.user_codes[i] == "d5"){
			customer.frequency[26]++;
			customer.total += 70;
		}
	}
	
	cout<<"===========================================\n";
	//will display the inputted info
	cout<<"CUSTOMER NAME: "<<customer.name<<endl;
	cout<<"CUSTOMER ADDRESS: "<<customer.address<<endl;
	cout<<"CUSTOMER CONTACT NUMBER: "<<customer.contact_number<<endl;
	cout<<"SUMMARY OF ORDER\n";
	int count = 0;//will keep count how many are UNIQUE orders//needed for display
	for(int i = 0; i < 27; i++){//getting and displaying UNIQUE ORDERS
		if(customer.frequency[i] > 0){
			cout<<customer.frequency[i]<<" * "<<customer.orders[i]<<endl;
			count++;
		}
	}
	//will confirm if the order is correct
	cout<<"\tIS THIS ORDER CORRECT?\n";
	cout<<"\t\t1 - YES\n";
	cout<<"\t\t2 - NO, Input Again\n";
	cout<<"\t\t3 - CANCEL ORDER\n";
	CORRECT:
	cout<<"\t\tInput 1,2 or 3: "; int choice; cin>>choice; cin.ignore();
	switch(choice){
		case 1:{//display the amount due
			cout<<"===========================================\n";
			cout<<"TOTAL AMOUNT DUE: "<<customer.total<<endl;
			time_t curr_time;
			curr_time = time(NULL);
			char *tm = ctime(&curr_time);
			strcpy(customer.time, tm);
			cout<<"DATE and TIME of ORDER: "<<customer.time;
			cout<<"Press any key..."<<endl; getch();
			write.open("Order.txt", ios::app);//writing it on the text
			write << "========================================================================\n\n";
			write << "CUSTOMER NAME: " <<customer.name<<endl;
			write << "CUSTOMER ADDRESS: "<<customer.address<<endl;
			write << "CUSTOMER CONTACT NUMBER: "<<customer.contact_number<<endl;
			write<<"CUSTOMER ORDER"<<endl;
			write << "------------------------------------------"<<endl;
			for(int i = 0; i < 27; i++){//getting and displaying UNIQUE ORDERS
				if(customer.frequency[i] > 0){
					write<<"\t"<<customer.frequency[i]<<" * "<<customer.orders[i]<<endl;
				}
			}
			write <<"TOTAL AMOUNT DUE: " <<customer.total<<endl;
			write << customer.time<<endl;
			write.close();
			break;
		}
		case 2:{//ask for input again
			goto ORDER;
			break;
		}
		case 3:{//cancel orders
			cout<<"ORDER HAS BEEN CANCELLED\n";
			cout<<"Press any key..."<<endl; getch();
			break;
		}
		default:{//if other number is pressed, ask again
			cout<<"INVALID INPUT.";
			goto CORRECT;
			break;
		}
	}
	system ("cls");
	system ("MAIN.exe");
	return 0;
}
