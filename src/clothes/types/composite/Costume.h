#ifndef LAUNDRY_COSTUME_H
#define LAUNDRY_COSTUME_H

#include "../../Clothing.h"
#include "../../../washing/Washable.h"

class Costume : public Clothing, public Washable {
public:
    Costume(double weight, bool hasDarkColor) : Clothing(weight, hasDarkColor, true) {
        // TODO - costume ar trebuie sa fie composite... pants, jacket, shirt
    }
};

#endif //LAUNDRY_COSTUME_H
