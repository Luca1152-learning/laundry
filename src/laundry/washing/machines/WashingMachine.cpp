#include "WashingMachine.h"

// Public
WashingMachine::WashingMachine(double weightCapacity, double cycleCompletionDuration, bool canWashHeavyClothes)
        : m_weightCapacity(weightCapacity), m_cycleCompletionDuration(cycleCompletionDuration),
          m_canWashHeavyClothes(canWashHeavyClothes), m_id(++lastId) {}

bool WashingMachine::canAddItemToQueue(Washable *item) {
    auto clothingItem = dynamic_cast<Clothing *>(item);
    if (not m_canWashHeavyClothes and clothingItem->isHeavy()) {
        return false;
    }

    return getQueueWeight() + clothingItem->getWeight() <= m_weightCapacity;
}

bool WashingMachine::isAtLeastHalfFull() const {
    return getQueueWeight() >= (m_weightCapacity / 2);
}

bool WashingMachine::canWashHeavyClothes() const {
    return m_canWashHeavyClothes;
}

bool WashingMachine::hasDarkColoredClothesInQueue() const {
    for (auto &item: m_queue) {
        auto clothingItem = dynamic_cast<Clothing *>(item);
        if (clothingItem->hasDarkColor()) {
            return true;
        }
    }
    return false;
}

bool WashingMachine::hasLightColoredClothesInQueue() const {
    for (auto &item: m_queue) {
        auto clothingItem = dynamic_cast<Clothing *>(item);
        if (not clothingItem->hasDarkColor()) {
            return true;
        }
    }
    return false;
}

// Protected
void WashingMachine::updateHistory(Washable *item) {
    stringstream cycleCompletionDurationSS, necessaryDetergentQuantitySS;
    cycleCompletionDurationSS << fixed << setprecision(1) << m_cycleCompletionDuration;
    necessaryDetergentQuantitySS << fixed << setprecision(1) << item->getNecessaryDetergentQuantity();

    item->addHistoryEvent(
            "WASH | " + cycleCompletionDurationSS.str() + " minutes | " +
            necessaryDetergentQuantitySS.str() + "g detergent used | " +
            "Washing Machine #" + to_string(getId())
    );
    item->addTimeSpentInMachine(m_cycleCompletionDuration);
    item->addDetergentUsed(item->getNecessaryDetergentQuantity());
}

int WashingMachine::getId() const {
    return m_id;
}

// Private
int WashingMachine::lastId = 0;