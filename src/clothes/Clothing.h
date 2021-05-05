#ifndef LAUNDRY_CLOTHING_H
#define LAUNDRY_CLOTHING_H

#include "types/ClothingType.h"

class Clothing {
public:
    Clothing(double weight, bool hasDarkColor, bool isHeavy) :
            m_weight(weight), m_hasDarkColor(hasDarkColor), m_isHeavy(isHeavy) {}

    double getWeight() const {
        return m_weight;
    }

    bool hasDarkColor() const {
        return m_hasDarkColor;
    }

    virtual ~Clothing() = default;

private:
    const double m_weight;
    const bool m_isHeavy, m_hasDarkColor;
};

#endif //LAUNDRY_CLOTHING_H
