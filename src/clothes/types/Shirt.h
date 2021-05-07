#ifndef LAUNDRY_SHIRT_H
#define LAUNDRY_SHIRT_H

#include "../Clothing.h"
#include "../../laundry/washing/Washable.h"

class Shirt : public Clothing, public Washable {
public:
    explicit Shirt(double weight, bool hasDarkColor, double minWashingTemperature, double maxWashingTemperature);

    double getNecessaryIroningTime() const override;

    double getNecessaryDetergentQuantity() const override;
};

#endif //LAUNDRY_SHIRT_H
