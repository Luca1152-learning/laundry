#include "WashingMachine.h"

// Public
WashingMachine::WashingMachine(double weightCapacity, double cycleCompletionDuration, bool canWashHeavyClothes)
        : m_weightCapacity(weightCapacity), m_cycleCompletionDuration(cycleCompletionDuration),
          m_canWashHeavyClothes(canWashHeavyClothes) {}

bool WashingMachine::canAddItemToQueue(Washable *item) {
    auto clothingItem = dynamic_cast<Clothing *>(item);
    return getQueueWeight() + clothingItem->getWeight() <= m_weightCapacity;
}

bool WashingMachine::isAtLeastHalfFull() const {
    return getQueueWeight() >= (m_weightCapacity / 2);
}

bool WashingMachine::canWashHeavyClothes() const {
    return m_canWashHeavyClothes;
}

double WashingMachine::getWeightCapacity() const {
    return m_weightCapacity;
}

// Protected
void WashingMachine::updateHistory(Washable *item) {
    item->addHistoryEvent(
            "WASH | " + to_string(m_cycleCompletionDuration) + "s | " +
            to_string(item->getNecessaryDetergentQuantity()) + "g detergent used | " +
            "Washing Machine #" + to_string(getId())
    );
}