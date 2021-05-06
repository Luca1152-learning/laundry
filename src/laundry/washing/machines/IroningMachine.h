#ifndef LAUNDRY_IRONINGMACHINE_H
#define LAUNDRY_IRONINGMACHINE_H

#include "Machine.h"

class IroningMachine : public Machine {
public:
    bool canAddItemToQueue(Washable *item) override {
        return m_queue.empty();
    }

protected:
    void updateHistory(Washable *item) override {
        item->addHistoryEvent(
                string("IRON | ") + to_string(item->getNecessaryIroningTime()) + "s | " +
                "Ironing Machine #" + to_string(getId())
        );
    }
};

#endif //LAUNDRY_IRONINGMACHINE_H
