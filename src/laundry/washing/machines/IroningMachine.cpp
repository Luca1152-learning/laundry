#include "IroningMachine.h"

// Public
void IroningMachine::run() {
    for (auto &item: m_queue) {
        item->markAsIroned();
    }
    Machine::run();
}

bool IroningMachine::canAddItemToQueue(Washable *item) {
    return m_queue.empty();
}

IroningMachine::IroningMachine() : m_id(++lastId) {}


// Protected
void IroningMachine::updateHistory(Washable *item) {
    stringstream necessaryIroningTimeSS;
    necessaryIroningTimeSS << fixed << setprecision(1) << item->getNecessaryIroningTime();

    item->addHistoryEvent(
            string("IRON | ") + necessaryIroningTimeSS.str() + " minutes | " +
            "Ironing Machine #" + to_string(getId())
    );
    item->addTimeSpentInMachine(item->getNecessaryIroningTime());
}

int IroningMachine::getId() const {
    return m_id;
}

// Private
int IroningMachine::lastId = 0;