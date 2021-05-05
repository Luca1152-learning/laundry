#ifndef LAUNDRY_IRONINGMACHINE_H
#define LAUNDRY_IRONINGMACHINE_H

#include "Machine.h"

class IroningMachine : public Machine {
public:
    explicit IroningMachine() : Machine(0) {}

    void queueItem(Washable *item) override {
        Machine::queueItem(item);
    }

private:
    const int m_itemsCapacity = 1;
};

#endif //LAUNDRY_IRONINGMACHINE_H
