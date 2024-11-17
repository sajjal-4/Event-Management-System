#include "Event.h"
#include <iostream>
using namespace std;

Event::Event(string n, string d, string l, int noa, float p) {
    name = n;
    date = d;
    location = l;
    no_of_attendees = noa;
    price_per_attendee = p;
}

void Event::Display() {
    cout << endl << "\tInformation of " << name << " Event:";
    cout << endl << "\tName: " << name << endl;
    cout << "\tDate: " << date << endl;
    cout << "\tLocation: " << location << endl;
    cout << "\tNumber of Attendees: " << no_of_attendees << endl;
    cout << "\tPrice Per Attendee: " << price_per_attendee << endl;
}

void Event::Get() {
    cout << endl << "\tEnter Name: ";
    getline(cin, name);
    cout << "\tEnter date: ";
    getline(cin, date);
    cout << "\tEnter location: ";
    getline(cin, location);
    
    do {
        cout << "\tEnter No Of Attendees: ";
        cin >> no_of_attendees;
    } while (no_of_attendees < 0);
    
    do {
        cout << "\tEnter Price Per Attendee: ";
        cin >> price_per_attendee;
    } while (price_per_attendee < 0);
}

bool Event::operator==(Event& e) {
    return date == e.date;
}

int Event::tellAwards() {
    return 0;
}

float Event::tellRating() {
    return 0;
}
