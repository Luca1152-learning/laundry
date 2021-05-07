#include "IroningMachine.h"

// Public
bool IroningMachine::canAddItemToQueue(Washable *item) {
    return m_queue.empty();
}

// Protected
void IroningMachine::updateHistory(Washable *item) {
    item->addHistoryEvent(
            string("IRON | ") + to_string(item->getNecessaryIroningTime()) + "s | " +
            "Ironing Machine #" + to_string(getId())
    );
}