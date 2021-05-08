#include "WashingMachine.h"

// Public
void WashingMachine::run() {
    if (not m_queue.empty() and not m_isTemperatureSet) {
        throw runtime_error("This washing machine's temperature wasn't set.");
    }
    for (auto &item: m_queue) {
        item->markAsWashed();
    }
    Machine::run();
    m_isTemperatureSet = false;
}

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
    stringstream cycleCompletionDurationSS, necessaryDetergentQuantitySS, temperatureSS;
    cycleCompletionDurationSS << fixed << setprecision(1) << m_cycleCompletionDuration;
    necessaryDetergentQuantitySS << fixed << setprecision(1) << item->getNecessaryDetergentQuantity();
    temperatureSS << fixed << setprecision(1) << m_temperature;

    item->addHistoryEvent(
            "WASH | " + cycleCompletionDurationSS.str() + " minutes | " +
            necessaryDetergentQuantitySS.str() + "g detergent used | " +
            "Washing Machine #" + to_string(getId()) + " (" + temperatureSS.str() + "ºC)"
    );
    item->addTimeSpentInMachine(m_cycleCompletionDuration);
    item->addDetergentUsed(item->getNecessaryDetergentQuantity());
}

int WashingMachine::getId() const {
    return m_id;
}

void WashingMachine::setTemperature(double temperature) {
    if (m_isTemperatureSet) {
        throw runtime_error("The temperature was already set. That's unexpected.");
    }

    m_temperature = temperature;
    m_isTemperatureSet = true;
}

bool WashingMachine::isTemperatureSet() {
    return m_isTemperatureSet;
}

double WashingMachine::getTemperature() {
    return m_temperature;
}

// Private
int WashingMachine::lastId = 0;