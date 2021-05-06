#ifndef LAUNDRY_WASHABLEUTILS_H
#define LAUNDRY_WASHABLEUTILS_H

#include "../washing/Washable.h"
#include "../clothes/types/ClothingType.h"
#include "../clothes/types/Coat.h"
#include "../clothes/types/composite/Costume.h"
#include "../clothes/types/Dress.h"
#include "../clothes/types/Windbreaker.h"

class WashableUtils {
public:
    static Washable *makeClothingItem(
            ClothingType clothingType, double weight, bool hasDarkColor,
            double minWashingTemperature, double maxWashingTemperature
    ) {
        switch (clothingType) {
            case ClothingType::COAT:return new Coat(weight, hasDarkColor, minWashingTemperature, maxWashingTemperature);
            case ClothingType::COSTUME:
                // TODO
                return new Costume(
                        weight, hasDarkColor, minWashingTemperature, maxWashingTemperature,
                        weight, hasDarkColor, minWashingTemperature, maxWashingTemperature,
                        weight, hasDarkColor, minWashingTemperature, maxWashingTemperature
                );
            case ClothingType::DRESS:
                return new Dress(weight, hasDarkColor, minWashingTemperature, maxWashingTemperature);
            case ClothingType::JACKET:
                return new Jacket(weight, hasDarkColor, minWashingTemperature, maxWashingTemperature);
            case ClothingType::PANTS:
                return new Pants(weight, hasDarkColor, minWashingTemperature, maxWashingTemperature);
            case ClothingType::SHIRT:
                return new Shirt(weight, hasDarkColor, minWashingTemperature, maxWashingTemperature);
            case ClothingType::WINDBREAKER:
                return new Windbreaker(weight, hasDarkColor, minWashingTemperature, maxWashingTemperature);
        }
    }
};

#endif //LAUNDRY_WASHABLEUTILS_H
