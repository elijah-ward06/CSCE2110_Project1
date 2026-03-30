#include <iostream>
#include <string>
#include "database.hpp"
#include "tools/date.hpp"
#include "tools/location.hpp"

using namespace std;

void displayMenu() {
  cout << "   CITY COUNCIL DRIVER DATABASE" << endl;
  cout << "1. Search Driver by ID (O(1))" << endl;
  cout << "2. Add New Driver Record" << endl;
  cout << "3. Move Driver to Inactive Database" << endl;
  cout << "4. Retrieve N Most Recent Licenses" << endl;
  cout << "5. Retrieve N Oldest Licenses" << endl;
  cout << "6. View Total Driver Count" << endl;
  cout << "7. Exit" << endl;
  cout << "Enter your choice: ";
}

int main(){
  DriverDatabase db;
  // Need to make
      int choice;
    do {
        displayMenu();
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (choice) {
            case 1: { // O(1) Search
                int id;
                cout << "Enter Driver ID: ";
                cin >> id;
                Driver* d = db.findDriver(id);
                if (d) {
                    d->display();
                } else {
                    cout << "Driver with ID " << id << " not found." << endl;
                }
                break;
            }

            case 2: { // Add Record
                int id, exp;
                string name, dobStr, street, city, state, work, med, licStr;
                
                cout << "Enter ID: "; cin >> id;
                cout << "Enter Name: "; cin.ignore(); getline(cin, name);
                cout << "Enter DOB (M/D/Y): "; cin >> dobStr;
                cout << "Enter Street: "; cin.ignore(); getline(cin, street);
                cout << "Enter City: "; getline(cin, city);
                cout << "Enter State: "; getline(cin, state);
                cout << "Enter Work Category: "; getline(cin, work);
                cout << "Enter Experience (Years): "; cin >> exp;
                cout << "Enter Medical Condition: "; cin.ignore(); getline(cin, med);
                cout << "Enter License Issue Date (M/D/Y): "; cin >> licStr;

                Location loc = {street, city, state};
                Driver* newDriver = new Driver(id, name, Date(dobStr), loc, work, exp, med, Date(licStr));
                db.addDriver(newDriver);
                cout << "Driver added successfully!" << endl;
                break;
            }

            case 3: { // Migration
                int id;
                cout << "Enter ID to move to Inactive: ";
                cin >> id;
                db.moveToInactive(id);
                cout << "Driver moved to inactive database." << endl;
                break;
            }

            case 4: { // N Most Recent
                int n;
                cout << "Enter N: ";
                cin >> n;
                Driver** results = db.getNewest(n);
                cout << "\n Most Recent Licenses " << endl;
                for (int i = 0; i < n && i < db.totalDrivers(); i++) {
                    results[i]->display();
                }
                delete[] results;
                break;
            }

            case 5: { // N Oldest
                int n;
                cout << "Enter N: ";
                cin >> n;
                Driver** results = db.getOldest(n);
                cout << "\n Oldest Licenses " << endl;
                for (int i = 0; i < n && i < db.totalDrivers(); i++) {
                    results[i]->display();
                }
                delete[] results;
                break;
            }

            case 6:
                cout << "Total Active Drivers: " << db.totalDrivers() << endl;
                break;

            case 7:
                cout << "Exiting system..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
