#ifndef LAUNDRY_LAUNDRY_H
#define LAUNDRY_LAUNDRY_H

#include <vector>
#include <iostream>
#include "washing/Washable.h"
#include "clothes/types/ClothingType.h"
#include "clothes/types/Coat.h"
#include "clothes/types/composite/Costume.h"
#include "clothes/types/Dress.h"
#include "clothes/types/Jacket.h"
#include "clothes/types/Pants.h"
#include "clothes/types/Shirt.h"
#include "clothes/types/Windbreaker.h"

using namespace std;

class Laundry {
public:

    void addClothingItemToWash(ClothingType clothingType, double weight, bool hasDarkColor) {
        m_clothesToWash.push_back(makeClothingItem(clothingType, weight, hasDarkColor));
    }

private:
    vector<const Washable *> m_clothesToWash, m_clothesToWring, m_clothesToDry, m_clothesToIron, m_clothesCleaned;

    static Washable *makeClothingItem(ClothingType clothingType, double weight, bool hasDarkColor) {
        switch (clothingType) {
            case ClothingType::COAT: return new Coat(weight, hasDarkColor);
            case ClothingType::COSTUME: return new Costume(weight, hasDarkColor);
            case ClothingType::DRESS: return new Dress(weight, hasDarkColor);
            case ClothingType::JACKET: return new Jacket(weight, hasDarkColor);
            case ClothingType::PANTS: return new Pants(weight, hasDarkColor);
            case ClothingType::SHIRT: return new Shirt(weight, hasDarkColor);
            case ClothingType::WINDBREAKER: return new Windbreaker(weight, hasDarkColor);
        }
    }
};

#endif //LAUNDRY_LAUNDRY_H
