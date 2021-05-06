#ifndef LAUNDRY_WASHINGMACHINE_H
#define LAUNDRY_WASHINGMACHINE_H

#include "Machine.h"

class WashingMachine : public Machine {
public:
    explicit WashingMachine(double weightCapacity, double cycleCompletionDuration, bool canWashHeavyClothes = false)
            : m_weightCapacity(weightCapacity), m_cycleCompletionDuration(cycleCompletionDuration),
              m_canWashHeavyClothes(canWashHeavyClothes) {
    }

    bool canAddItemToQueue(Washable *item) override {
        auto clothingItem = dynamic_cast<Clothing *>(item);
        return getQueueWeight() + clothingItem->getWeight() <= m_weightCapacity;
    }

    bool isAtLeastHalfFull() const {
        return getQueueWeight() >= (m_weightCapacity / 2);
    }

protected:
    void updateHistory(Washable *item) override {
        item->addHistoryEvent(
                "WASH | " + to_string(m_cycleCompletionDuration) + "s | " +
                to_string(item->getNecessaryDetergentQuantity()) + "g detergent used | " +
                "Washing Machine #" + to_string(getId())
        );
    }

public:

    bool canWashHeavyClothes() const {
        return m_canWashHeavyClothes;
    }

    double getWeightCapacity() const {
        return m_weightCapacity;
    }

private:
    const double m_weightCapacity, m_cycleCompletionDuration;
    const bool m_canWashHeavyClothes;
};

#endif //LAUNDRY_WASHINGMACHINE_H
