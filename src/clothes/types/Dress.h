#ifndef LAUNDRY_DRESS_H
#define LAUNDRY_DRESS_H

#include "../Clothing.h"
#include "../../washing/Washable.h"

class Dress : public Clothing, public Washable {
public:
    explicit Dress(double weight, bool hasDarkColor) : Clothing(weight, hasDarkColor, false) {}

    double getNecessaryDetergentQuantity() const override {
        // As per the requirements
        return Washable::STANDARD_DETERGENT_QUANTITY;
    }
};

#endif //LAUNDRY_DRESS_H
