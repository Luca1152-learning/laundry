#ifndef LAUNDRY_MACHINE_H
#define LAUNDRY_MACHINE_H

#include "../Washable.h"
#include "../../../clothes/Clothing.h"
#include <vector>

using namespace std;

class Machine {
public:
    explicit Machine() : m_id(++lastId) {}

    void queueItem(Washable *item) {
        if (canAddItemToQueue(item)) {
            m_queue.push_back(item);
        } else {
            throw runtime_error("The given item can't be added to the queue.");
        }
    }

    virtual bool canAddItemToQueue(Washable *item) = 0;

    void run() {
        for (auto &item: m_queue) {
            updateHistory(item);
        }
        m_queue.clear();
    }

    virtual ~Machine() = default;

protected:
    vector<Washable *> m_queue;
    const int m_id;

    virtual void updateHistory(Washable *item) = 0;

    double getQueueWeight() const {
        double weight = 0;
        for (auto &it: m_queue) {
            auto clothingItem = dynamic_cast<Clothing *>(it);
            weight += clothingItem->getWeight();
        }
        return weight;
    }

    int getId() const {
        return m_id;
    }

private:
    static int lastId;
};

#endif //LAUNDRY_MACHINE_H
