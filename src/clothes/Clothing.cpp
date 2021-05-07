#include "Clothing.h"

int Clothing::lastId = 0;

Clothing::Clothing(double weight, bool hasDarkColor, bool isHeavy)
        : m_weight(weight), m_hasDarkColor(hasDarkColor), m_isHeavy(isHeavy), m_id(++lastId) {}

double Clothing::getWeight() const {
    return m_weight;
}

bool Clothing::hasDarkColor() const {
    return m_hasDarkColor;
}

bool Clothing::isHeavy() const {
    return m_isHeavy;
}

int Clothing::getId() const {
    return m_id;
}
