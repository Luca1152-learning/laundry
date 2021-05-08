#ifndef LAUNDRY_WRINGERMACHINE_H
#define LAUNDRY_WRINGERMACHINE_H

#include "Machine.h"
#include <sstream>
#include <iomanip>

// Masina de stors haine
class WringerMachine : public Machine {
public:
    void run() override;

    explicit WringerMachine(double weightCapacity, double cycleCompletionDuration);

    bool canAddItemToQueue(Washable *item) override;

    bool isAtLeastHalfFull() const;

protected:
    int getId() const override;

    void updateHistory(Washable *item) override;

private:
    const double m_weightCapacity, m_cycleCompletionDuration;
    const int m_id;

    static int lastId;
};

#endif //LAUNDRY_WRINGERMACHINE_H
