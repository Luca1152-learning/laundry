#include "Pants.h"

// Public
Pants::Pants(
        double weight, bool hasDarkColor, double minWashingTemperature, double maxWashingTemperature, bool isSuitPiece
) : Clothing(weight, hasDarkColor, false), Washable(minWashingTemperature, maxWashingTemperature),
    m_isSuitPiece(isSuitPiece) {}

double Pants::getNecessaryDetergentQuantity() const {
    return (hasDarkColor()) ? 2 * Washable::STANDARD_DETERGENT_QUANTITY : Washable::STANDARD_DETERGENT_QUANTITY;
}

double Pants::getNecessaryIroningTime() const {
    // 90s/kg, as per the requirements
    return 90 * getWeight();
}

bool Pants::isSuitPiece() const {
    return m_isSuitPiece;
}

