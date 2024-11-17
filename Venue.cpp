#include "Venue.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

void Venue::Read() {
    string s1, s2, s3, s4, s5, s6, s7, s8;
    ifstream file1("Event.txt");
    
    for (int i = 0; i < MAX; i++) {
        getline(file1, s1, ':');
        getline(file1, s2, ':');
        getline(file1, s3, ':');
        getline(file1, s4, ':');
        getline(file1, s5, ':');
        getline(file1, s6, ':');
        getline(file1, s7, ':');
        getline(file1, s8);
        
        if (s1 == "WORKSHOP") {
            E[i] = new Workshop(s2, s3, s4, stoi(s5), stoi(s6), s7, stoi(s8));
        } else {
            E[i] = new Exhibition(s2, s3, s4, stoi(s5), stoi(s6), s7, stof(s8));
        }
    }
    file1.close();
}

void Venue::DisplayData() {
    int b = 0, c = 0;
    cout << endl << "=> INFORMATION OF ALL EVENTS: " << endl;
    cout << endl << "=> Information Of All Workshops:" << endl;
    
    for (int i = 0; i < MAX; i++) {
        if (E[i]->IsWorkshop()) {
            b++;
            E[i]->Display();
        }
    }
    
    if (b == 0) {
        cout << endl << "\tNo Workshops Booked." << endl;
    }

    cout << endl << "=> Information Of All Exhibitions:" << endl;
    
    for (int i = 0; i < MAX; i++) {
        if (!E[i]->IsWorkshop()) {
            c++;
            E[i]->Display();
        }
    }
    
    if (c == 0) {
        cout << endl << "\tNo Exhibitions Booked." << endl;
    }
    
    cout << endl << "=> Total Workshops Booked: " << b << endl;
    cout << endl << "=> Total Exhibitions Booked: " << c << endl;
    cout << endl << "=> Total Booked Events: " << b + c << endl;
}

void Venue::FindEvent() {
    string a;
    cout << endl << "=> ENTER NAME OF EVENT: ";
    cin.ignore();
    getline(cin, a);
    bool found = false;
    
    for (int i = 0; i < MAX && !found; i++) {
        if (a == E[i]->tellName()) {
            E[i]->Display();
            found = true;
        }
    }
    
    if (!found) {
        cout << endl << "o Event Not Found." << endl;
    }
}

void Venue::PopularEvent() {
    int a = 0;
    bool found = false;
    cout << endl << "=> INFORMATION OF POPULAR EVENT(S): " << endl;
    
    for (int i = 0; i < MAX; i++) {
        if (E[i]->IsPopular()) {
            a++;
            E[i]->Display();
            found = true;
        }
    }
    
    cout << endl << "=> Total Popular Events Booked: " << a << endl;
    if (!found) {
        cout << endl << "o No Popular Event Found." << endl;
    }
}

void Venue::LargestEvent() {
    int a = E[0]->tellAttendees();
    int b = 0;
    
    for (int i = 1; i < MAX; i++) {
        if (a < E[i]->tellAttendees()) {
            a = E[i]->tellAttendees();
            b = i;
        }
    }
    
    cout << endl << "=> INFORMATION OF LARGEST EVENT: " << endl;
    E[b]->Display();
}

void Venue::CheapestEvent() {
    float a = E[0]->tellPrice();
    int b = 0;
    
    for (int i = 1; i < MAX; i++) {
        if (a > E[i]->tellPrice()) {
            a = E[i]->tellPrice();
            b = i;
        }
    }
    
    cout << endl << "=> INFORMATION OF CHEAPEST EVENT: " << endl;
    E[b]->Display();
}

void Venue::EventOnSameDay() {
    int a = 0;
    string t1, t2;
    bool found = false;
    cout << endl << "=> INFORMATION OF EVENTS ON SAME DAY: " << endl;
    
    for (int i = 0; i < MAX; i++) {
        for (int j = i + 1; j < MAX; j++) {
            t1 = E[i]->tellDate();
            t2 = E[j]->tellDate();
            if (t1 == t2) {
                a++;
                cout << endl << "o Events Occurring On Same Day: " << E[i]->tellName() << " and " << E[j]->tellName() << endl;
                E[i]->Display();
                E[j]->Display();
                found = true;
            }
        }
    }
    
    cout << endl << "=> Set Of Events Occurring On Same Day: " << a << endl;
}

void Venue::Update() {
    string title;
    bool found = false;
    cout << endl << "=> ENTER NAME OF EVENT: ";
    cin.ignore();
    getline(cin, title);
    
    for (int i = 0; i < MAX && !found; i++) {
        if (title == E[i]->tellName()) {
            cout << endl << "=> Current Information Stored for " << E[i]->tellName() << " Event: " << endl;
            E[i]->Display();
            cout << endl << "=> Enter Updated Information: " << endl;
            E[i]->Get();
            WriteToFile();
            cout << endl << "o Information Updated Successfully." << endl;
            found = true;
        }
    }
    
    if (!found) {
        cout << endl << "o Event Not Found." << endl;
    }
}

void Venue::WriteToFile() {
    ofstream file1("Event.txt");
    
    for (int i = 0; i < MAX; i++) {
        file1 << E[i]->TypeOfEvent() << ":" << E[i]->tellName() << ":" << E[i]->tellDate() << ":" << E[i]->tellLocation() << ":" << E[i]->tellPrice() << ":" << E[i]->tellAttendees() << ":" << E[i]->Attribute1() << ":";
        
        if (E[i]->IsWorkshop())
            file1 << E[i]->tellAwards() << endl;
        else
            file1 << E[i]->tellRating() << endl;
    }
}

void Venue::WriteToOutputFile() {
    ofstream file1("Output.txt");
    
    for (int i = 0; i < MAX; i++) {
        file1 << E[i]->TypeOfEvent() << ":" << E[i]->tellName() << ":" << E[i]->tellDate() << ":" << E[i]->tellLocation() << ":" << E[i]->tellPrice() << ":" << E[i]->tellAttendees() << ":" << E[i]->Attribute1() << ":";
        
        if (E[i]->TypeOfEvent() == "WORKSHOP")
            file1 << E[i]->tellAwards() << endl;
        else
            file1 << E[i]->tellRating() << endl;
    }
    
    cout << endl << "o Information Written Successfully.";
}

void Venue::Revenue_Generated() {
    int total = 0;
    
    for (int i = 0; i < MAX; i++) {
        cout << endl << "=> Revenue Generated From " << E[i]->tellName() << " : " << E[i]->RevenueGenerated() << endl;
        total += E[i]->RevenueGenerated();
    }
    
    cout << endl << "o Total Revenue Generated From All Events: " << total << endl;
}

void Venue::RevenueOfAnEvent() {
    string a;
    cout << endl << "=> ENTER NAME OF EVENT: ";
    cin.ignore();
    getline(cin, a);
    bool found = false;
    
    for (int i = 0; i < MAX && !found; i++) {
        if (a == E[i]->tellName()) {
            cout << endl << "o Revenue Generated: " << E[i]->RevenueGenerated() << endl;
            found = true;
        }
    }
    
    if (!found) {
        cout << endl << "o Event Not Found." << endl;
    }
}

void Venue::RevenueWorkshop() {
    int total = 0;
    bool found = false;
    
    for (int i = 0; i < MAX; i++) {
        if (E[i]->IsWorkshop()) {
            cout << endl << "=> Workshop Booked: " << E[i]->tellName() << endl;
            total += E[i]->RevenueGenerated();
            found = true;
        }
    }
    
    if (found) {
        cout << endl << "o Total Revenue Generated From Workshops: " << total << endl;
    } else {
        cout << endl << "o No Workshops Found." << endl;
    }
}

void Venue::ReveueExhibition() {
    int total = 0;
    bool found = false;
    
    for (int i = 0; i < MAX; i++) {
        if (!E[i]->IsWorkshop()) {
            cout << endl << "=> Exhibition Booked: " << E[i]->tellName() << endl;
            total += E[i]->RevenueGenerated();
            found = true;
        }
    }
    
    if (found) {
        cout << endl << "o Total Revenue Generated: " << total << endl;
    } else {
        cout << endl << "o No Exhibitions Found." << endl;
    }
}

void Venue::GreatestRevenue() {
    int a = E[0]->RevenueGenerated();
    int b = 0;
    
    for (int i = 1; i < MAX; i++) {
        if (a < E[i]->RevenueGenerated()) {
            a = E[i]->RevenueGenerated();
            b = i;
        }
    }
    
    cout << endl << "=> Highest Revenue Obtained From " << E[b]->tellName() << " :" << endl;
    E[b]->Display();
    cout << endl << "\tRevenue Generated: " << a << endl;
}

void Venue::LowestRevenue() {
    int a = E[0]->RevenueGenerated();
    int b = 0;
    
    for (int i = 1; i < MAX; i++) {
        if (a > E[i]->RevenueGenerated()) {
            a = E[i]->RevenueGenerated();
            b = i;
        }
    }
    
    cout << endl << "=> Lowest Revenue Obtained From " << E[b]->tellName() << " :" << endl;
    E[b]->Display();
    cout << endl << "\tRevenue Generated: " << a << endl;
}

Venue::~Venue() {
    for (int i = 0; i < MAX; i++) {
        delete E[i];
    }
}
