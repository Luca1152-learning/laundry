#ifndef LAUNDRY_DRYINGMACHINE_H
#define LAUNDRY_DRYINGMACHINE_H

#include "Machine.h"

class DryingMachine : public Machine {
public:
    explicit DryingMachine(int itemsCapacity, double cycleCompletionDuration)
            : m_itemsCapacity(itemsCapacity), m_cycleCompletionDuration(cycleCompletionDuration) {
    }

    bool canAddItemToQueue(Washable *item) override {
        return m_queue.size() != m_itemsCapacity;
    }

    bool isAtLeastHalfFull() const {
        return m_queue.size() >= (m_itemsCapacity / 2);
    }

protected:
    void updateHistory(Washable *item) override {
        item->addHistoryEvent(
                "DRY | " + to_string(m_cycleCompletionDuration) + "s | " +
                "Drying Machine #" + to_string(getId())
        );
    }

private:
    const int m_itemsCapacity;
    const double m_cycleCompletionDuration;
};

#endif //LAUNDRY_DRYINGMACHINE_H
