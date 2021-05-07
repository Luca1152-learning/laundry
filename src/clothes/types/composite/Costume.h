#ifndef LAUNDRY_COSTUME_H
#define LAUNDRY_COSTUME_H

#include "../../Clothing.h"
#include "../../../laundry/washing/Washable.h"
#include "../Pants.h"
#include "../Shirt.h"
#include "../Jacket.h"

class Costume : public Washable {
public:
    explicit Costume(
            double pantsWeight, bool pantsHaveDarkColor,
            double pantsMinWashingTemperature, double pantsMaxWashingTemperature,
            double shirtWeight, bool shirtHasDarkColor,
            double shirtMinWashingTemperature, double shirtMaxWashingTemperature,
            double jacketWeight, bool jacketHasDarkColor,
            double jacketMinWashingTemperature, double jacketMaxWashingTemperature
    );

    double getNecessaryDetergentQuantity() const override;

    double getNecessaryIroningTime() const override;

private:
    Pants m_pants;
    Shirt m_shirt;
    Jacket m_jacket;
};

#endif //LAUNDRY_COSTUME_H
