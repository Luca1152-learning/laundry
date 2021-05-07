#include "WashingMachine.h"

// Public
WashingMachine::WashingMachine(double weightCapacity, double cycleCompletionDuration, bool canWashHeavyClothes)
        : m_weightCapacity(weightCapacity), m_cycleCompletionDuration(cycleCompletionDuration),
          m_canWashHeavyClothes(canWashHeavyClothes), m_id(++lastId) {}

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
    stringstream cycleCompletionDurationSS, necessaryDetergentQuantitySS;
    cycleCompletionDurationSS << fixed << setprecision(1) << m_cycleCompletionDuration;
    necessaryDetergentQuantitySS << fixed << setprecision(1) << item->getNecessaryDetergentQuantity();

    item->addHistoryEvent(
            "WASH | " + cycleCompletionDurationSS.str() + "s | " +
            necessaryDetergentQuantitySS.str() + "g detergent used | " +
            "Washing Machine #" + to_string(getId())
    );
}

int WashingMachine::getId() const {
    return m_id;
}

// Private
int WashingMachine::lastId = 0;