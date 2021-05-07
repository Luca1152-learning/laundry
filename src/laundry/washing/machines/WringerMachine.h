#ifndef LAUNDRY_WRINGERMACHINE_H
#define LAUNDRY_WRINGERMACHINE_H

#include "Machine.h"

// Masina de stors haine
class WringerMachine : public Machine {
public:
    explicit WringerMachine(double weightCapacity, double cycleCompletionDuration);

    bool canAddItemToQueue(Washable *item) override;

    bool isAtLeastHalfFull() const;

protected:
    void updateHistory(Washable *item) override;

private:
    const double m_weightCapacity, m_cycleCompletionDuration;
};

#endif //LAUNDRY_WRINGERMACHINE_H
