#ifndef LAUNDRY_CLOTHING_H
#define LAUNDRY_CLOTHING_H

class Clothing {
private:
    const double m_weight;
    const bool m_isHeavy, m_hasDarkColor;
public:
    Clothing(double weight, bool hasDarkColor, bool isHeavy) :
            m_weight(weight), m_hasDarkColor(hasDarkColor), m_isHeavy(isHeavy) {}

    bool hasDarkColor() const {
        return m_hasDarkColor;
    }
};

#endif //LAUNDRY_CLOTHING_H
