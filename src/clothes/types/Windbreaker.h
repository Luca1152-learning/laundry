#ifndef LAUNDRY_WINDBREAKER_H
#define LAUNDRY_WINDBREAKER_H

#include "../Clothing.h"
#include "../../laundry/washing/Washable.h"

// Geacă
class Windbreaker : public Clothing, public Washable {
public:
    explicit Windbreaker(double weight, bool hasDarkColor, double minWashingTemperature, double maxWashingTemperature);

    double getNecessaryDetergentQuantity() const override;
};

#endif //LAUNDRY_WINDBREAKER_H
