#ifndef LAUNDRY_COAT_H
#define LAUNDRY_COAT_H

#include "../Clothing.h"
#include "../../washing/Washable.h"

class Coat : public Clothing, public Washable {
public:
    Coat(double weight, bool hasDarkColor)
            : Clothing(weight, hasDarkColor, true), Washable(false, false) {
    }

    double getNecessaryDetergentQuantity() const override {
        // As per the requirements
        return 100;
    }
};

#endif //LAUNDRY_COAT_H
