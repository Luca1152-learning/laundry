#ifndef LAUNDRY_SHIRT_H
#define LAUNDRY_SHIRT_H

#include "../Clothing.h"
#include "../../washing/Washable.h"

class Shirt : public Clothing, public Washable {
public:
    Shirt(double weight, bool hasDarkColor) : Clothing(weight, hasDarkColor, false) {}
};

#endif //LAUNDRY_SHIRT_H
