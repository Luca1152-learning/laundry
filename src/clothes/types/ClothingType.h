#ifndef LAUNDRY_CLOTHINGTYPE_H
#define LAUNDRY_CLOTHINGTYPE_H

#include <string>

using namespace std;

enum class ClothingType {
    COAT,
    SUIT,
    DRESS,
    JACKET,
    PANTS,
    SHIRT,
    WINDBREAKER,
};

class ClothingTypeUtils {
public:
    static string toString(ClothingType clothingType);
};

#endif //LAUNDRY_CLOTHINGTYPE_H
