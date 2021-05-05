#ifndef LAUNDRY_CLOTHING_H
#define LAUNDRY_CLOTHING_H

class Clothing {
private:
    double m_weight;
    bool m_isHeavy;
    bool m_hasDarkColor;
public:
    Clothing(double weight, bool hasDarkColor, bool isHeavy) :
            m_weight(weight), m_hasDarkColor(hasDarkColor), m_isHeavy(isHeavy) {}
};

#endif //LAUNDRY_CLOTHING_H
