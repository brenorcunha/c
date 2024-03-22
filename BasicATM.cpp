#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
	unsigned long int card;
	int option;
	float value, balance = 1000;
	
	cout<<"Welcome to our bank.\n";
	cout<<"Type your card number to continue: \n";
	cin>>card;
	
	if(card<40000000){
		cout<<"Sorry... Invalid card, try again.";
		system("cls");
		main();
	} else {
		cout<<"Type the option you want: \n";
		cout<<"1 withdrawal 2 Deposit 3 View balance \n";
		cin>>option;
		switch(option){
			case 1:
				cout<<"Enter the amount to be withdrawn: Ex: 2000: \n";
				cin>>value;
				if(balance-value <0){
					cout<<"Invalid operation, try again.";
					system("pause");
		system("cls");
		main();
				} else {
					balance = balance-value;
					cout<<"OK, your balance is \n";
					cout<<balance;
					cout<<"\n";
					option=1;
				}
				
				case 2:
				cout<<"Enter the amount to be deposited: Ex; 2000";
				cin>>value;
				balance = balance+value;
				cout<<"OK, your balance is \n";
					cout<<balance;
					cout<<"\n";
			    case 3:
					cout<<"OK, your balance is \n";
					cout<<balance;
					cout<<"\n";
		}
	}
	system("pause");
	system("cls");
	main();
	return(0);
}
