#ifndef LAUNDRY_WASHINGHISTORY_H
#define LAUNDRY_WASHINGHISTORY_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class WashingHistory {
public:
    void addHistoryEvent(const string &historyEvent) {
        m_historyEvents.push_back(historyEvent);
    }

    void printHistory() {
        cout << "-----\n";
        for (auto &it: m_historyEvents) {
            cout << it << "\n";
        }
        cout << "-----\n";
    }

private:
    vector<string> m_historyEvents;
};

#endif //LAUNDRY_WASHINGHISTORY_H
