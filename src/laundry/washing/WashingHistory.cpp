#include "WashingHistory.h"

// Public
void WashingHistory::addHistoryEvent(const string &historyEvent) {
    m_historyEvents.push_back(historyEvent);
}

void WashingHistory::printHistory() {
    cout << "-----\n";
    for (auto &it: m_historyEvents) {
        cout << it << "\n";
    }
    cout << "-----\n";
}