#ifndef LAUNDRY_MACHINE_H
#define LAUNDRY_MACHINE_H

#include "../Washable.h"
#include "../../../clothes/Clothing.h"
#include <vector>

using namespace std;

class Machine {
public:
    explicit Machine();

    void queueItem(Washable *item);

    virtual bool canAddItemToQueue(Washable *item) = 0;

    void run();

    virtual ~Machine() = default;

protected:
    vector<Washable *> m_queue;
    const int m_id;

    virtual void updateHistory(Washable *item) = 0;

    double getQueueWeight() const;

    int getId() const;

private:
    static int lastId;
};

#endif //LAUNDRY_MACHINE_H
