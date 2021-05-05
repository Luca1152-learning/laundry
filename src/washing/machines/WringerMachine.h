#ifndef LAUNDRY_WRINGERMACHINE_H
#define LAUNDRY_WRINGERMACHINE_H

#include "Machine.h"

// Masina de stors haine
class WringerMachine : public Machine {
public:
    explicit WringerMachine(double weightCapacity, double cycleCompletionDuration)
            : Machine(cycleCompletionDuration), m_weightCapacity(weightCapacity) {}

private:
    const double m_weightCapacity;
};

#endif //LAUNDRY_WRINGERMACHINE_H
