#include "Event.h"
#include <string>

class Exhibition : public Event {
private:
    string exhibitor;
    float rating;

public:
    Exhibition(string n, string d, string l, int noa, float p, string e, float r);
    void Display();
    void Get();
    
    bool IsPopular() {
        return rating > 3.5;
    }
    
    bool IsWorkshop() {
        return false;
    }
    
    string Attribute1() {
        return exhibitor;
    }
    
    float tellRating() {
        return rating;
    }
    
    string TypeOfEvent() {
        return "EXHIBITION";
    }
};
