#ifndef LAUNDRY_HISTORYOBJECT_H
#define LAUNDRY_HISTORYOBJECT_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class HistoryObject {
public:
    void addHistoryEvent(const string &historyEvent);

    void printHistory();

    double getDetergentUsed();

    double getTimeSpentInMachines();

    void addDetergentUsed(double quantity);

    void addTimeSpentInMachine(double time);

private:
    vector<string> m_historyEvents;
    double m_detergentUsed = 0, m_timeSpentInMachines = 0;
};

#endif //LAUNDRY_HISTORYOBJECT_H
