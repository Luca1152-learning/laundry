#ifndef LAUNDRY_WRINGERMACHINE_H
#define LAUNDRY_WRINGERMACHINE_H

// Masina de stors haine
class WringerMachine {
public:
    explicit WringerMachine(double weightCapacity) : m_weightCapacity(weightCapacity) {}

private:
    const double m_weightCapacity;
};

#endif //LAUNDRY_WRINGERMACHINE_H
