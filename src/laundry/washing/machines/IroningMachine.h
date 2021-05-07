#ifndef LAUNDRY_IRONINGMACHINE_H
#define LAUNDRY_IRONINGMACHINE_H

#include "Machine.h"
#include <sstream>
#include <iomanip>

class IroningMachine : public Machine {
public:
    explicit IroningMachine();

protected:
    int getId() const override;

public:

    bool canAddItemToQueue(Washable *item) override;

protected:
    void updateHistory(Washable *item) override;

private:
    const int m_id;

    static int lastId;
};

#endif //LAUNDRY_IRONINGMACHINE_H
