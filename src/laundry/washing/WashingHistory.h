#ifndef LAUNDRY_WASHINGHISTORY_H
#define LAUNDRY_WASHINGHISTORY_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class WashingHistory {
public:
    void addHistoryEvent(const string &historyEvent);

    void printHistory();

private:
    vector<string> m_historyEvents;
};

#endif //LAUNDRY_WASHINGHISTORY_H
