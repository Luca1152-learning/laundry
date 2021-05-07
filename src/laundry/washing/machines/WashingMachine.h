#ifndef LAUNDRY_WASHINGMACHINE_H
#define LAUNDRY_WASHINGMACHINE_H

#include "Machine.h"

class WashingMachine : public Machine {
public:
    explicit WashingMachine(double weightCapacity, double cycleCompletionDuration, bool canWashHeavyClothes = false);

    bool canAddItemToQueue(Washable *item) override;

    bool isAtLeastHalfFull() const;

    bool canWashHeavyClothes() const;

    double getWeightCapacity() const;

protected:
    void updateHistory(Washable *item) override;

private:
    const double m_weightCapacity, m_cycleCompletionDuration;
    const bool m_canWashHeavyClothes;
};

#endif //LAUNDRY_WASHINGMACHINE_H
