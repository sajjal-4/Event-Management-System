#include "Event.h"
#include <string>

class Workshop : public Event {
private:
    string instructor;
    int awards_won;

public:
    Workshop(string n, string d, string l, int noa, float p, string i, int a);
    void Display();
    void Get();
    
    bool IsPopular() {
        return awards_won > 8;
    }
    
    bool IsWorkshop() {
        return true;
    }
    
    string Attribute1() {
        return instructor;
    }
    
    int tellAwards() {
        return awards_won;
    }
    
    string TypeOfEvent() {
        return "WORKSHOP";
    }
};
