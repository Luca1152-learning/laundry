#ifndef LAUNDRY_DRYINGMACHINE_H
#define LAUNDRY_DRYINGMACHINE_H

class DryingMachine {
public:
    explicit DryingMachine(int itemsCapacity) : m_itemsCapacity(itemsCapacity) {}

private:
    const int m_itemsCapacity;
};

#endif //LAUNDRY_DRYINGMACHINE_H
