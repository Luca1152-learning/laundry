#include "Shirt.h"

// Public
Shirt::Shirt(double weight, bool hasDarkColor, double minWashingTemperature, double maxWashingTemperature)
        : Clothing(weight, hasDarkColor, false),
          Washable(minWashingTemperature, maxWashingTemperature) {}

double Shirt::getNecessaryIroningTime() const {
    // 120s/kg, as per the requirements
    return 120 * getWeight();
}

double Shirt::getNecessaryDetergentQuantity() const {
    // As per the requirements
    return Washable::STANDARD_DETERGENT_QUANTITY;
}