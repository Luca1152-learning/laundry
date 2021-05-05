#ifndef LAUNDRY_PANTS_H
#define LAUNDRY_PANTS_H

#include "../Clothing.h"
#include "../../washing/Washable.h"

class Pants : public Clothing, public Washable {
public:
    Pants(double weight, bool hasDarkColor) : Clothing(weight, hasDarkColor, false) {}

    double getNecessaryDetergentQuantity() const override {
        return (hasDarkColor()) ? 2 * Washable::STANDARD_DETERGENT_QUANTITY : Washable::STANDARD_DETERGENT_QUANTITY;
    }
};

#endif //LAUNDRY_PANTS_H
