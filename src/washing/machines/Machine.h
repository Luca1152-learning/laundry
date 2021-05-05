#ifndef LAUNDRY_MACHINE_H
#define LAUNDRY_MACHINE_H

#include "../Washable.h"
#include <vector>

using namespace std;

class Machine {
public:
    explicit Machine(double cycleCompletionDuration) : m_cycleCompletionDuration(cycleCompletionDuration) {}

    virtual void queueItem(Washable *item) {
        queue.push_back(item);
    }

    virtual ~Machine() = default;

protected:
    vector<Washable *> queue;

private:
    double m_cycleCompletionDuration;
};

#endif //LAUNDRY_MACHINE_H
