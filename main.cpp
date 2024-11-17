#include "Venue.h"
#include <iostream>
using namespace std;

class InvalidInput {
public:
    void what() {
        cout << endl << "=> Invalid Input. Try Again!" << endl;
    }
};

int main() {
    Venue V;
    V.Read();
    int choice;
    cout << "------WELCOME TO THE EVENT MANAGEMENT SYSTEM!------" << endl;

    do {
        try {
            cout << endl << "***********EVENT MANAGEMENT SYSTEM***********" << endl;
            cout << endl << "\tMENU OPTIONS" << endl;
            cout << "=> Choose From The Following:" << endl;
            cout << "1. Display Information of All Events." << endl;
            cout << "2. Display Information of A Particular Event." << endl;
            cout << "3. Display Information of Popular Events." << endl;
            cout << "4. Display Information of Cheapest Event." << endl;
            cout << "5. Display Information of Largest Event." << endl;
            cout << "6. Display Events Occurring On Same Date." << endl;
            cout << "7. Update Information
