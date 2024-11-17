#pragma once
#include <string>
using namespace std;

class Event {
private:
    string name;
    string date;
    string location;
    int price_per_attendee;
    int no_of_attendees;

public:
    Event(string n, string d, string l, int noa, float p);
    virtual bool IsWorkshop() = 0;
    virtual bool IsPopular() = 0;
    virtual string Attribute1() = 0;
    virtual string TypeOfEvent() = 0;
    virtual void Display();
    virtual void Get();
    bool operator==(Event& e);
    virtual int tellAwards();
    virtual float tellRating();
    
    int RevenueGenerated() {
        return price_per_attendee * no_of_attendees;
    }
    
    string tellName() { return name; }
    string tellDate() { return date; }
    string tellLocation() { return location; }
    float tellPrice() { return price_per_attendee; }
    int tellAttendees() { return no_of_attendees; }
};
