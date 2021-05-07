#include "DryingMachine.h"

// Public
DryingMachine::DryingMachine(int itemsCapacity, double cycleCompletionDuration)
        : m_itemsCapacity(itemsCapacity), m_cycleCompletionDuration(cycleCompletionDuration) {}

bool DryingMachine::canAddItemToQueue(Washable *item) {
    return m_queue.size() != m_itemsCapacity;
}

bool DryingMachine::isAtLeastHalfFull() const {
    return m_queue.size() >= (m_itemsCapacity / 2);
}

// Protected
void DryingMachine::updateHistory(Washable *item) {
    item->addHistoryEvent(
            "DRY | " + to_string(m_cycleCompletionDuration) + "s | " +
            "Drying Machine #" + to_string(getId())
    );
}

