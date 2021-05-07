#include "HistoryObject.h"

// Public
void HistoryObject::addHistoryEvent(const string &historyEvent) {
    m_historyEvents.push_back(historyEvent);
}

void HistoryObject::printHistory() {
    cout << "-----\n";
    for (auto &it: m_historyEvents) {
        cout << it << "\n";
    }
    cout << "-----\n";
}

double HistoryObject::getDetergentUsed() {
    return m_detergentUsed;
}

double HistoryObject::getTimeSpentInMachines() {
    return m_timeSpentInMachines;
}

void HistoryObject::addDetergentUsed(double quantity) {
    if (quantity < 0) {
        runtime_error("The quantity of detergent used can't be negative.");
    }

    m_detergentUsed += quantity;
}

void HistoryObject::addTimeSpentInMachine(double time) {
    if (time < 0) {
        runtime_error("The time spent in a machine can't be negative.");
    }

    m_timeSpentInMachines += time;
}
