#ifndef LAUNDRY_WASHABLEUTILS_H
#define LAUNDRY_WASHABLEUTILS_H

#include "../laundry/washing/Washable.h"
#include "../clothes/types/ClothingType.h"
#include "../clothes/types/Coat.h"
#include "../clothes/types/Dress.h"
#include "../clothes/types/Windbreaker.h"
#include "../clothes/types/Jacket.h"
#include "../clothes/types/Pants.h"
#include "../clothes/types/Shirt.h"

class WashableUtils {
public:
    static Washable *makeClothingItem(
            ClothingType clothingType, double weight, bool hasDarkColor,
            double minWashingTemperature, double maxWashingTemperature,
            bool isSuitPiece = false
    );

    static ClothingType getClothingType(Washable *washable);

    static bool isSuitPiece(Washable *washable);
};

#endif //LAUNDRY_WASHABLEUTILS_H
