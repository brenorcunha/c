#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    int op, id;
    string dr, specialty;
    cout << "Welcome to EmergencyCare!";
    cout << "Click on the desired option: \n";
    cout << "1 Pediatrics 2 General Practitioner 3 Geriatrics 4 Check hospitalizations\n";
    cin >> op;

    // After asking the user to enter the medical specialty, it will direct to the doctors who provide that specialty.
    switch (op) {
        case 1:
            specialty = "Pediatrician";
            cout << "Choose the doctor: \n";
            cout << "1 Dr. Paulo 2 Dr. Jose 3 Dr. Andreia or 4 to go back to the previous menu.\n";
            cin >> op;
            switch (op) {
                case 1:
                    dr = "Paulo";
                    cout << "Consultation with " + specialty + " Dr. " + dr + ". \n";
                    system("pause");
                case 2:
                    dr = "Jose";
                    cout << "Consultation with " + specialty + " Dr. " + dr + ". \n";
                    system("pause");
                case 3:
                    dr = "Andreia";
                    cout << "Consultation with " + specialty + " Dr. " + dr + ". \n";
                    system("pause");
                default:
                    system("cls");
                    main();
            }
        case 2:
            specialty = "General Practitioner";
            cout << "Choose the doctor: \n";
            cout << "1 Dr. Lucas \n2 Dr. Breno or \n3 to go back to the previous menu. \n";
            cin >> op;
            switch (op) {
                case 1:
                    dr = "Lucas";
                    cout << "Consultation with " + specialty + " Dr. " + dr + ". \n";
                    system("pause");
                case 2:
                    dr = "Breno";
                    cout << "Consultation with " + specialty + " Dr. " + dr + ". \n";
                    system("pause");
                default:
                    system("cls");
                    main();
            }
        case 3:
            specialty = "Geriatrician";
            cout << "Choose the doctor: \n";
            cout << "1 Dr. Marcelo or \n2 to go back to the previous menu. \n";
            cin >> op;
            switch (op) {
                case 1:
                    dr = "Marcelo";
                    cout << "Consultation with " + specialty + " Dr. " + dr + ". \n";
                    system("pause");
                default:
                    system("cls");
                    main();
            }
        case 4:
            specialty = "hospitalization";
            dr = "";
            cout << "Enter the ID of the hospitalization or the patient: \n";
            cin >> id;
			cout<<"Consultation with "+ specialty + " ID: ";
			cout<<id;
			cout<<"...";
			cout<<"\n";
			system("pause");
	}

//At least, clear the screen and goes back to the start.

    system("cls");
    main();
    return(0);
}
