#include "Jacket.h"

// Public
Jacket::Jacket(double weight, bool hasDarkColor, double minWashingTemperature, double maxWashingTemperature)
        : Clothing(weight, hasDarkColor, true),
          Washable(minWashingTemperature, maxWashingTemperature, false, false) {}

double Jacket::getNecessaryDetergentQuantity() const {
    // 100g/kg, as per the requirements
    return 100 * getWeight();
}

double Jacket::getNecessaryIroningTime() const {
    // 90s/kg, as per the requirements
    return 150 * getWeight();
}