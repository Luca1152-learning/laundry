#include "DryingMachine.h"

// Public
DryingMachine::DryingMachine(int itemsCapacity, double cycleCompletionDuration)
        : m_itemsCapacity(itemsCapacity), m_cycleCompletionDuration(cycleCompletionDuration), m_id(++lastId) {}


void DryingMachine::run() {
    for (auto &item: m_queue) {
        item->markAsDried();
    }
    Machine::run();
}


bool DryingMachine::canAddItemToQueue(Washable *item) {
    return m_queue.size() != m_itemsCapacity;
}

bool DryingMachine::isAtLeastHalfFull() const {
    return m_queue.size() >= (m_itemsCapacity / 2);
}

// Protected
void DryingMachine::updateHistory(Washable *item) {
    stringstream cycleCompletionDurationSS;
    cycleCompletionDurationSS << fixed << setprecision(1) << m_cycleCompletionDuration;
    item->addHistoryEvent(
            "DRY | " + cycleCompletionDurationSS.str() + " minutes | " +
            "Drying Machine #" + to_string(getId())
    );
    item->addTimeSpentInMachine(m_cycleCompletionDuration);
}

int DryingMachine::getId() const {
    return m_id;
}


// Private
int DryingMachine::lastId = 0;