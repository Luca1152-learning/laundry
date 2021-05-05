#ifndef LAUNDRY_JACKET_H
#define LAUNDRY_JACKET_H

#include "../Clothing.h"
#include "../../washing/Washable.h"

// Sacou
class Jacket : public Clothing, public Washable {
public:
    Jacket(double weight, bool hasDarkColor)
            : Clothing(weight, hasDarkColor, true), Washable(false, false) {
    }
};

#endif //LAUNDRY_JACKET_H
