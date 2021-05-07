#ifndef LAUNDRY_CLOTHING_H
#define LAUNDRY_CLOTHING_H

#include "types/ClothingType.h"

class Clothing {
public:
    Clothing(double weight, bool hasDarkColor, bool isHeavy);

    double getWeight() const;

    bool hasDarkColor() const;

    bool isHeavy() const;

    int getId() const;

    virtual ~Clothing() = default;

private:
    const double m_weight;
    const bool m_isHeavy, m_hasDarkColor;
    const int m_id;
    static int lastId;
};

#endif //LAUNDRY_CLOTHING_H
