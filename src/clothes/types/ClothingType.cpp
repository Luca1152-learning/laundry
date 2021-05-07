#include "ClothingType.h"

string ClothingTypeUtils::toString(ClothingType clothingType) {
    switch (clothingType) {
        case ClothingType::COAT: return "Coat";
        case ClothingType::COSTUME: return "Costume";
        case ClothingType::DRESS: return "Dress";
        case ClothingType::JACKET: return "Jacket";
        case ClothingType::PANTS: return "Pants";
        case ClothingType::SHIRT: return "Shirt";
        case ClothingType::WINDBREAKER: return "Windbreaker";
    }
}