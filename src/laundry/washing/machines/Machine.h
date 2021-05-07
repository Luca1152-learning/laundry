#ifndef LAUNDRY_MACHINE_H
#define LAUNDRY_MACHINE_H

#include "../Washable.h"
#include "../../../clothes/Clothing.h"
#include <vector>

using namespace std;

class Machine {
public:
    void queueItem(Washable *item);

    virtual bool canAddItemToQueue(Washable *item) = 0;

    void run();

    virtual ~Machine() = default;

protected:
    vector<Washable *> m_queue;

    virtual void updateHistory(Washable *item) = 0;

    double getQueueWeight() const;

    virtual int getId() const = 0;
};

#endif //LAUNDRY_MACHINE_H
