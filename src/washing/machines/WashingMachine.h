#ifndef LAUNDRY_WASHINGMACHINE_H
#define LAUNDRY_WASHINGMACHINE_H

#include "Machine.h"

class WashingMachine : public Machine {
public:
    explicit WashingMachine(double weightCapacity, bool canWashHeavyClothes = false) :
            m_weightCapacity(weightCapacity), m_canWashHeavyClothes(canWashHeavyClothes) {
    }

private:
    const double m_weightCapacity;
    const bool m_canWashHeavyClothes;
};

#endif //LAUNDRY_WASHINGMACHINE_H
