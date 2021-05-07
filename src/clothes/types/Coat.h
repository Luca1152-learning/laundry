#ifndef LAUNDRY_COAT_H
#define LAUNDRY_COAT_H

#include "../Clothing.h"
#include "../../laundry/washing/Washable.h"

class Coat : public Clothing, public Washable {
public:
    explicit Coat(double weight, bool hasDarkColor, double minWashingTemperature, double maxWashingTemperature);

    double getNecessaryDetergentQuantity() const override;
};

#endif //LAUNDRY_COAT_H
