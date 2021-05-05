#ifndef LAUNDRY_WINDBREAKER_H
#define LAUNDRY_WINDBREAKER_H

#include "../Clothing.h"
#include "../../washing/Washable.h"

// Geacă
class Windbreaker : public Clothing, public Washable {
public:
    Windbreaker(double weight, bool hasDarkColor) : Clothing(weight, hasDarkColor, true) {
    }

    double getNecessaryDetergentQuantity() const override {
        // As per the requirements
        return 100;
    }
};

#endif //LAUNDRY_WINDBREAKER_H
