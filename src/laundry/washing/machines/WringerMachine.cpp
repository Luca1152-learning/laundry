#include "WringerMachine.h"

// Public
WringerMachine::WringerMachine(double weightCapacity, double cycleCompletionDuration)
        : m_weightCapacity(weightCapacity), m_cycleCompletionDuration(cycleCompletionDuration) {}

bool WringerMachine::canAddItemToQueue(Washable *item) {
    auto clothingItem = dynamic_cast<Clothing *>(item);
    return getQueueWeight() + clothingItem->getWeight() <= m_weightCapacity;
}

bool WringerMachine::isAtLeastHalfFull() const {
    return getQueueWeight() >= (m_weightCapacity / 2);
}

// Protected
void WringerMachine::updateHistory(Washable *item) {
    item->addHistoryEvent(
            "WRING | " + to_string(m_cycleCompletionDuration) + "s | " +
            "Wringer Machine #" + to_string(getId())
    );
}

