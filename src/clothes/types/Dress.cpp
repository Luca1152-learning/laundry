#include "Dress.h"

Dress::Dress(double weight, bool hasDarkColor, double minWashingTemperature, double maxWashingTemperature)
        : Clothing(weight, hasDarkColor, false), Washable(minWashingTemperature, maxWashingTemperature) {}

double Dress::getNecessaryDetergentQuantity() const {
    // As per the requirements
    return Washable::STANDARD_DETERGENT_QUANTITY;
}

double Dress::getNecessaryIroningTime() const {
    return 60 * getWeight();
}
