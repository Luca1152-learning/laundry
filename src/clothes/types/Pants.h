#ifndef LAUNDRY_PANTS_H
#define LAUNDRY_PANTS_H

#include "../Clothing.h"
#include "../../washing/Washable.h"

class Pants : public Clothing, public Washable {
public:
    explicit Pants(double weight, bool hasDarkColor, double minWashingTemperature, double maxWashingTemperature)
            : Clothing(weight, hasDarkColor, false), Washable(minWashingTemperature, maxWashingTemperature) {}

    double getNecessaryDetergentQuantity() const override {
        return (hasDarkColor()) ? 2 * Washable::STANDARD_DETERGENT_QUANTITY : Washable::STANDARD_DETERGENT_QUANTITY;
    }

    double getNecessaryIroningTime() const override {
        // 90s/kg, as per the requirements
        return 90 * getWeight();
    }
};

#endif //LAUNDRY_PANTS_H
