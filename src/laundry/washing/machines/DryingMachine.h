#ifndef LAUNDRY_DRYINGMACHINE_H
#define LAUNDRY_DRYINGMACHINE_H

#include "Machine.h"

class DryingMachine : public Machine {
public:
    explicit DryingMachine(int itemsCapacity, double cycleCompletionDuration);

    bool canAddItemToQueue(Washable *item) override;

    bool isAtLeastHalfFull() const;

protected:
    void updateHistory(Washable *item) override;

private:
    const int m_itemsCapacity;
    const double m_cycleCompletionDuration;
};

#endif //LAUNDRY_DRYINGMACHINE_H
