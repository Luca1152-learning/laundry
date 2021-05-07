#include "WringerMachine.h"

// Public
WringerMachine::WringerMachine(double weightCapacity, double cycleCompletionDuration)
        : m_weightCapacity(weightCapacity), m_cycleCompletionDuration(cycleCompletionDuration), m_id(++lastId) {}

bool WringerMachine::canAddItemToQueue(Washable *item) {
    auto clothingItem = dynamic_cast<Clothing *>(item);
    return getQueueWeight() + clothingItem->getWeight() <= m_weightCapacity;
}

bool WringerMachine::isAtLeastHalfFull() const {
    return getQueueWeight() >= (m_weightCapacity / 2);
}

// Protected
void WringerMachine::updateHistory(Washable *item) {
    stringstream cycleCompletionDurationSS;
    cycleCompletionDurationSS << fixed << setprecision(1) << m_cycleCompletionDuration;

    item->addHistoryEvent(
            "WRING | " + cycleCompletionDurationSS.str() + " minutes | " +
            "Wringer Machine #" + to_string(getId())
    );
    item->addTimeSpentInMachine(m_cycleCompletionDuration);
}

int WringerMachine::getId() const {
    return m_id;
}

// Private
int WringerMachine::lastId = 0;
