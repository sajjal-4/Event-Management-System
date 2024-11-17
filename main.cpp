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
            cout << endl << endl << "***********EVENT MANAGEMENT SYSTEM***********" << endl;
            cout << endl << "\t" << "\t" << "MENU OPTIONS" << endl;
            cout << "=> Choose From The Following:" << endl;
            cout << "1. Display Information of All Events." << endl;
            cout << "2. Display Information of A Particular Event." << endl;
            cout << "3. Display Information of Popular Events." << endl;
            cout << "4. Display Information of Cheapest Event." << endl;
            cout << "5. Display Information of Largest Event." << endl;
            cout << "6. Display Events Occurring On Same Date." << endl;
            cout << "7. Update Information of An Event." << endl;
            cout << "8. Write Information To File 'Output.txt'." << endl;
            cout << "9. Display Revenue Generated." << endl;
            cout << "- Display Revenue Generated From All Events." << endl;
            cout << "- Display Revenue Generated From A Particular Event." << endl;
            cout << "- Display Revenue Generated From All Workshop Events." << endl;
            cout << "- Display Revenue Generated From All Exhibition Events." << endl;
            cout << "- Show Details For The Event That Generated Highest Revenue." << endl;
            cout << "- Show Details For The Event That Generated Lowest Revenue." << endl;
            cout << "10. Exit." << endl;
            cout << endl << "Enter choice: ";
            cin >> choice;

            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                throw InvalidInput();
            }

            if (choice == 1) {
                V.DisplayData();
            } else if (choice == 2) {
                V.FindEvent();
            } else if (choice == 3) {
                V.PopularEvent();
            } else if (choice == 4) {
                V.CheapestEvent();
            } else if (choice == 5) {
                V.LargestEvent();
            } else if (choice == 6) {
                V.EventOnSameDay();
            } else if (choice == 7) {
                V.Update();
            } else if (choice == 8) {
                V.WriteToOutputFile();
            } else if (choice == 9) {
                int c;
                do {
                    cout << endl << "Choose From The Following:" << endl;
                    cout << "1. Display Revenue Generated From All Events." << endl;
                    cout << "2. Display Revenue Generated From A Particular Event." << endl;
                    cout << "3. Display Revenue Generated From All Workshop Events." << endl;
                    cout << "4. Display Revenue Generated From All Exhibition Events." << endl;
                    cout << "5. Show Details For The Event That Generated Highest Revenue." << endl;
                    cout << "6. Show Details For The Event That Generated Lowest Revenue." << endl;
                    cout << "7. Return to Menu." << endl;
                    cout << endl << "Enter choice: ";
                    cin >> c;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore();
                        throw InvalidInput();
                    }

                    if (c == 1) V.Revenue_Generated();
                    else if (c == 2) V.RevenueOfAnEvent();
                    else if (c == 3) V.RevenueWorkshop();
                    else if (c == 4) V.RevenueExhibition();
                    else if (c == 5) V.GreatestRevenue();
                    else if (c == 6) V.LowestRevenue();
                } while (c != 7);
            }
        } catch (InvalidInput e) {
            e.what();
        }
    } while (choice != 10);
    return 0;
}
