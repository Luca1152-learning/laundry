#ifndef LAUNDRY_COSTUME_H
#define LAUNDRY_COSTUME_H

#include "../../Clothing.h"
#include "../../../washing/Washable.h"
#include "../Pants.h"
#include "../Shirt.h"
#include "../Jacket.h"

class Costume : public Washable {
public:
    explicit Costume(double pantsWeight, bool pantsHaveDarkColor,
                     double shirtWeight, bool shirtHasDarkColor,
                     double jacketWeight, bool jacketHasDarkColor)
            : m_pants(pantsWeight, pantsHaveDarkColor),
              m_shirt(shirtWeight, shirtHasDarkColor),
              m_jacket(jacketWeight, jacketHasDarkColor) {}

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
