#ifndef LAUNDRY_WINDBREAKER_H
#define LAUNDRY_WINDBREAKER_H

#include "../Clothing.h"
#include "../../washing/Washable.h"

// Geacă
class Windbreaker : public Clothing, public Washable {
public:
    explicit Windbreaker(double weight, bool hasDarkColor, double minWashingTemperature, double maxWashingTemperature)
            : Clothing(weight, hasDarkColor, true),
              Washable(minWashingTemperature, maxWashingTemperature) {
    }

    double getNecessaryDetergentQuantity() const override {
        // 100g/kg, As per the requirements
        return 100 * getWeight();
    }
};

#endif //LAUNDRY_WINDBREAKER_H
