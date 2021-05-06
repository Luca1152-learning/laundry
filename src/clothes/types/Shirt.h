#ifndef LAUNDRY_SHIRT_H
#define LAUNDRY_SHIRT_H

#include "../Clothing.h"
#include "../../laundry/washing/Washable.h"

class Shirt : public Clothing, public Washable {
public:
    explicit Shirt(double weight, bool hasDarkColor, double minWashingTemperature, double maxWashingTemperature)
            : Clothing(weight, hasDarkColor, false),
              Washable(minWashingTemperature, maxWashingTemperature) {}

    double getNecessaryIroningTime() const override {
        // 120s/kg, as per the requirements
        return 120 * getWeight();
    }

    double getNecessaryDetergentQuantity() const override {
        // As per the requirements
        return Washable::STANDARD_DETERGENT_QUANTITY;
    }
};

#endif //LAUNDRY_SHIRT_H
