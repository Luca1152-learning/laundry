#ifndef LAUNDRY_COSTUME_H
#define LAUNDRY_COSTUME_H

#include "../../Clothing.h"
#include "../../../washing/Washable.h"
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
    ) : m_pants(pantsWeight, pantsHaveDarkColor, pantsMinWashingTemperature, pantsMaxWashingTemperature),
        m_shirt(shirtWeight, shirtHasDarkColor, shirtMinWashingTemperature, shirtMaxWashingTemperature),
        m_jacket(jacketWeight, jacketHasDarkColor, jacketMinWashingTemperature, jacketMaxWashingTemperature),
        Washable(10, 100) // TODO - Costume nu ar trebui sa fie Washable
    {}

    double getNecessaryDetergentQuantity() const override {
        return m_pants.getNecessaryDetergentQuantity() + m_shirt.getNecessaryDetergentQuantity() +
               m_jacket.getNecessaryDetergentQuantity();
    }

    double getNecessaryIroningTime() const override {
        return m_pants.getNecessaryIroningTime() + m_shirt.getNecessaryIroningTime() +
               m_jacket.getNecessaryIroningTime();
    }

private:
    Pants m_pants;
    Shirt m_shirt;
    Jacket m_jacket;
};

#endif //LAUNDRY_COSTUME_H
