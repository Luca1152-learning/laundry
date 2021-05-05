#ifndef LAUNDRY_COAT_H
#define LAUNDRY_COAT_H

#include "../Clothing.h"
#include "../../washing/Washable.h"

class Coat : public Clothing, public Washable {
public:
    explicit Coat(double weight, bool hasDarkColor)
            : Clothing(weight, hasDarkColor, true), Washable(false, false) {
    }

    double getNecessaryDetergentQuantity() const override {
        // 100g/kg As per the requirements
        return 100 * getWeight();
    }
};

#endif //LAUNDRY_COAT_H
