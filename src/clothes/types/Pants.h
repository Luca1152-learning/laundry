#ifndef LAUNDRY_PANTS_H
#define LAUNDRY_PANTS_H

#include "../Clothing.h"
#include "../../washing/Washable.h"

class Pants : public Clothing, public Washable {
public:
    Pants(double weight, bool hasDarkColor) : Clothing(weight, hasDarkColor, false) {}
};

#endif //LAUNDRY_PANTS_H
