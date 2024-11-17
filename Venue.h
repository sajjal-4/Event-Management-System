#include "Event.h"
#include "Workshop.h"
#include "Exhibition.h"
const int MAX = 10;

class Venue {
private:
    Event* E[MAX];

public:
    void Read();
    void DisplayData();
    void FindEvent();
    void PopularEvent();
    void CheapestEvent();
    void LargestEvent();
    void EventOnSameDay();
    void Update();
    void WriteToFile();
    void WriteToOutputFile();
    void Revenue_Generated();
    void RevenueOfAnEvent();
    void RevenueWorkshop();
    void ReveueExhibition();
    void GreatestRevenue();
    void LowestRevenue();
    ~Venue();
};
