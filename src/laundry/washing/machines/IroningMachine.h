#ifndef LAUNDRY_IRONINGMACHINE_H
#define LAUNDRY_IRONINGMACHINE_H

#include "Machine.h"

class IroningMachine : public Machine {
public:
    bool canAddItemToQueue(Washable *item) override;

protected:
    void updateHistory(Washable *item) override;
};

#endif //LAUNDRY_IRONINGMACHINE_H
