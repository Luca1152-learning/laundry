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
    static Washable *makeClothingItem(ClothingType clothingType, double weight, bool hasDarkColor) {
        switch (clothingType) {
            case ClothingType::COAT: return new Coat(weight, hasDarkColor);
            case ClothingType::COSTUME:
                return new Costume(weight, hasDarkColor, weight, hasDarkColor, weight, hasDarkColor);
            case ClothingType::DRESS: return new Dress(weight, hasDarkColor);
            case ClothingType::JACKET: return new Jacket(weight, hasDarkColor);
            case ClothingType::PANTS: return new Pants(weight, hasDarkColor);
            case ClothingType::SHIRT: return new Shirt(weight, hasDarkColor);
            case ClothingType::WINDBREAKER: return new Windbreaker(weight, hasDarkColor);
        }
    }
};

#endif //LAUNDRY_WASHABLEUTILS_H
