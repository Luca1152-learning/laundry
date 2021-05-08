#include "Shirt.h"

// Public
Shirt::Shirt(double weight, bool hasDarkColor,
             double minWashingTemperature, double maxWashingTemperature,
             bool isSuitPiece)
        : Clothing(weight, hasDarkColor, false),
          Washable(minWashingTemperature, maxWashingTemperature), m_isSuitPiece(isSuitPiece) {}

double Shirt::getNecessaryIroningTime() const {
    // 120s/kg, as per the requirements
    return 120 * getWeight();
}

double Shirt::getNecessaryDetergentQuantity() const {
    // As per the requirements
    return Washable::STANDARD_DETERGENT_QUANTITY;
}

bool Shirt::isSuitPiece() const {
    return m_isSuitPiece;
}