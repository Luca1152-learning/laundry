#ifndef LAUNDRY_WASHABLEUTILS_H
#define LAUNDRY_WASHABLEUTILS_H

#include "../laundry/washing/Washable.h"
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
    );
};

#endif //LAUNDRY_WASHABLEUTILS_H
