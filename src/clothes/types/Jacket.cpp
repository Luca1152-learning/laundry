#include "Jacket.h"

// Public
Jacket::Jacket(
        double weight, bool hasDarkColor,
        double minWashingTemperature, double maxWashingTemperature,
        bool isSuitPiece
) : Clothing(weight, hasDarkColor, true), Washable(minWashingTemperature, maxWashingTemperature),
    m_isSuitPiece(isSuitPiece) {}

double Jacket::getNecessaryDetergentQuantity() const {
    // 100g/kg, as per the requirements
    return 100 * getWeight();
}

double Jacket::getNecessaryIroningTime() const {
    // 90s/kg, as per the requirements
    return 150 * getWeight();
}

bool Jacket::isSuitPiece() const {
    return m_isSuitPiece;
}