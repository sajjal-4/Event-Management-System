#include "Workshop.h"
#include <iostream>
using namespace std;

Workshop::Workshop(string n, string d, string l, int noa, float p, string i, int a) : Event(n, d, l, noa, p) {
    instructor = i;
    awards_won = a;
}

void Workshop::Display() {
    Event::Display();
    cout << "\tInstructor: " << instructor << endl;
    cout << "\tAwards Won: " << awards_won << endl;
}

void Workshop::Get() {
    Event::Get();
    cout << "\tEnter instructor Name: ";
    cin.ignore();
    getline(cin, instructor);
    
    do {
        cout << "\tEnter Awards Won: ";
        cin >> awards_won;
    } while (awards_won < 0);
}
