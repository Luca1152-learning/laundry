#ifndef LAUNDRY_WRINGERMACHINE_H
#define LAUNDRY_WRINGERMACHINE_H

#include "Machine.h"

// Masina de stors haine
class WringerMachine : public Machine {
public:
    explicit WringerMachine(double weightCapacity, double cycleCompletionDuration)
            : m_weightCapacity(weightCapacity), m_cycleCompletionDuration(cycleCompletionDuration) {}

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
                "WRING | " + to_string(m_cycleCompletionDuration) + "s | " +
                "Wringer Machine #" + to_string(getId())
        );
    }

private:
    const double m_weightCapacity, m_cycleCompletionDuration;
};

#endif //LAUNDRY_WRINGERMACHINE_H
