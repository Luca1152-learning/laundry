#ifndef LAUNDRY_JACKET_H
#define LAUNDRY_JACKET_H

#include "../Clothing.h"
#include "../../washing/Washable.h"

// Sacou
class Jacket : public Clothing, public Washable {
public:
    explicit Jacket(double weight, bool hasDarkColor)
            : Clothing(weight, hasDarkColor, true), Washable(false, false) {
    }

    double getNecessaryDetergentQuantity() const override {
        // 100g/kg, as per the requirements
        return 100 * getWeight();
    }

    double getNecessaryIroningTime() const override {
        // 90s/kg, as per the requirements
        return 150 * getWeight();
    }
};

#endif //LAUNDRY_JACKET_H
