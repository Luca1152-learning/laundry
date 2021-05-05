#ifndef LAUNDRY_DRESS_H
#define LAUNDRY_DRESS_H

#include "../Clothing.h"
#include "../../washing/Washable.h"

class Dress : public Clothing, public Washable {
public:
    Dress(double weight, bool hasDarkColor) : Clothing(weight, hasDarkColor, false) {}
};

#endif //LAUNDRY_DRESS_H
