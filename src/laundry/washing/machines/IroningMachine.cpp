#include "IroningMachine.h"

// Public
bool IroningMachine::canAddItemToQueue(Washable *item) {
    return m_queue.empty();
}

IroningMachine::IroningMachine() : m_id(++lastId) {}


// Protected
void IroningMachine::updateHistory(Washable *item) {
    stringstream necessaryIroningTimeSS;
    necessaryIroningTimeSS << fixed << setprecision(1) << item->getNecessaryIroningTime();

    item->addHistoryEvent(
            string("IRON | ") + necessaryIroningTimeSS.str() + "m | " +
            "Ironing Machine #" + to_string(getId())
    );
}

int IroningMachine::getId() const {
    return m_id;
}

// Private
int IroningMachine::lastId = 0;