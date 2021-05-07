#ifndef LAUNDRY_DRESS_H
#define LAUNDRY_DRESS_H

#include "../Clothing.h"
#include "../../laundry/washing/Washable.h"

class Dress : public Clothing, public Washable {
public:
    explicit Dress(double weight, bool hasDarkColor, double minWashingTemperature, double maxWashingTemperature);

    double getNecessaryDetergentQuantity() const override;
};

#endif //LAUNDRY_DRESS_H
