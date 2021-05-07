#ifndef LAUNDRY_DRYINGMACHINE_H
#define LAUNDRY_DRYINGMACHINE_H

#include "Machine.h"
#include <sstream>
#include <iomanip>

class DryingMachine : public Machine {
public:
    explicit DryingMachine(int itemsCapacity, double cycleCompletionDuration);

    bool canAddItemToQueue(Washable *item) override;

    bool isAtLeastHalfFull() const;

protected:
    int getId() const override;

protected:
    void updateHistory(Washable *item) override;

private:
    const int m_itemsCapacity, m_id;
    const double m_cycleCompletionDuration;

    static int lastId;
};

#endif //LAUNDRY_DRYINGMACHINE_H
