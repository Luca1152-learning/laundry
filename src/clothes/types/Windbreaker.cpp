#include "Windbreaker.h"

Windbreaker::Windbreaker(double weight, bool hasDarkColor, double minWashingTemperature, double maxWashingTemperature)
        : Clothing(weight, hasDarkColor, true), Washable(minWashingTemperature, maxWashingTemperature) {}

double Windbreaker::getNecessaryDetergentQuantity() const {
    // 100g/kg, As per the requirements
    return 100 * getWeight();
}
