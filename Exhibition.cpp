#include "Exhibition.h"
#include <iostream>
using namespace std;

Exhibition::Exhibition(string n, string d, string l, int noa, float p, string e, float r) : Event(n, d, l, noa, p) {
    exhibitor = e;
    rating = r;
}

void Exhibition::Display() {
    Event::Display();
    cout << "\tExhibitor: " << exhibitor << endl;
    cout << "\tRating: " << rating << endl;
}

void Exhibition::Get() {
    Event::Get();
    cout << "\tEnter Exhibitor Name: ";
    cin.ignore();
    getline(cin, exhibitor);
    
    do {
        cout << "\tEnter Rating: ";
        cin >> rating;
    } while (rating < 0);
}
