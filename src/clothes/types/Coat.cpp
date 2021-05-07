#include "Coat.h"

// Public
Coat::Coat(double weight, bool hasDarkColor, double minWashingTemperature, double maxWashingTemperature)
        : Clothing(weight, hasDarkColor, true),
          Washable(minWashingTemperature, maxWashingTemperature, false, false) {}

double Coat::getNecessaryDetergentQuantity() const {
    // 100g/kg As per the requirements
    return 100 * getWeight();
}
