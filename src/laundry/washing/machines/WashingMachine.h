#ifndef LAUNDRY_WASHINGMACHINE_H
#define LAUNDRY_WASHINGMACHINE_H

#include "Machine.h"
#include <sstream>
#include <iomanip>

class WashingMachine : public Machine {
public:
    explicit WashingMachine(double weightCapacity, double cycleCompletionDuration, bool canWashHeavyClothes = false);

    bool canAddItemToQueue(Washable *item) override;

protected:
    int getId() const override;

public:
    void run() override;

    bool isAtLeastHalfFull() const;

    bool canWashHeavyClothes() const;

    bool hasDarkColoredClothesInQueue() const;

    bool hasLightColoredClothesInQueue() const;

    void setTemperature(double temperature);

    bool isTemperatureSet();

    double getTemperature();

protected:
    void updateHistory(Washable *item) override;

private:
    const double m_weightCapacity, m_cycleCompletionDuration;
    const bool m_canWashHeavyClothes;
    const int m_id;

    double m_temperature;
    bool m_isTemperatureSet = false;

    static int lastId;
};

#endif //LAUNDRY_WASHINGMACHINE_H
