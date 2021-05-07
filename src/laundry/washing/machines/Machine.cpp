#include "Machine.h"

// Public
Machine::Machine() : m_id(++lastId) {}

void Machine::queueItem(Washable *item) {
    if (canAddItemToQueue(item)) {
        m_queue.push_back(item);
    } else {
        throw runtime_error("The given item can't be added to the queue.");
    }
}

void Machine::run() {
    for (auto &item: m_queue) {
        updateHistory(item);
    }
    m_queue.clear();
}

// Protected
int Machine::lastId = 0;

double Machine::getQueueWeight() const {
    double weight = 0;
    for (auto &it: m_queue) {
        auto clothingItem = dynamic_cast<Clothing *>(it);
        weight += clothingItem->getWeight();
    }
    return weight;
}

int Machine::getId() const {
    return m_id;
}