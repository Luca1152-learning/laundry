#ifndef LAUNDRY_PANTS_H
#define LAUNDRY_PANTS_H

#include "../Clothing.h"
#include "../../laundry/washing/Washable.h"

class Pants : public Clothing, public Washable {
public:
    explicit Pants(double weight, bool hasDarkColor, double minWashingTemperature, double maxWashingTemperature);

    double getNecessaryDetergentQuantity() const override;

    double getNecessaryIroningTime() const override;
};

#endif //LAUNDRY_PANTS_H
