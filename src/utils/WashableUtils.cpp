#include "WashableUtils.h"

Washable *WashableUtils::makeClothingItem(
        ClothingType clothingType, double weight, bool hasDarkColor,
        double minWashingTemperature, double maxWashingTemperature, bool isSuitPiece
) {
    switch (clothingType) {
        case ClothingType::COAT:return new Coat(weight, hasDarkColor, minWashingTemperature, maxWashingTemperature);
        case ClothingType::DRESS:return new Dress(weight, hasDarkColor, minWashingTemperature, maxWashingTemperature);
        case ClothingType::JACKET:
            return new Jacket(weight, hasDarkColor, minWashingTemperature, maxWashingTemperature, isSuitPiece);
        case ClothingType::PANTS:
            return new Pants(weight, hasDarkColor, minWashingTemperature, maxWashingTemperature, isSuitPiece);
        case ClothingType::SHIRT:
            return new Shirt(weight, hasDarkColor, minWashingTemperature, maxWashingTemperature, isSuitPiece);
        case ClothingType::WINDBREAKER:
            return new Windbreaker(weight, hasDarkColor, minWashingTemperature, maxWashingTemperature);
        default: throw runtime_error("This clothing type can't be instantiated.");
    }
}

ClothingType WashableUtils::getClothingType(Washable *washable) {
    auto coat = dynamic_cast<Coat *>(washable);
    if (coat) return ClothingType::COAT;

    auto dress = dynamic_cast<Dress *>(washable);
    if (dress) return ClothingType::DRESS;

    auto jacket = dynamic_cast<Jacket *>(washable);
    if (jacket) return ClothingType::JACKET;

    auto pants = dynamic_cast<Pants *>(washable);
    if (pants) return ClothingType::PANTS;

    auto shirt = dynamic_cast<Shirt *>(washable);
    if (shirt) return ClothingType::SHIRT;

    auto windbreaker = dynamic_cast<Windbreaker *>(washable);
    if (windbreaker) return ClothingType::WINDBREAKER;

    throw runtime_error("Couldn't determine the Washable*'s clothing type.");
}

bool WashableUtils::isSuitPiece(Washable *washable) {
    auto jacket = dynamic_cast<Jacket *>(washable);
    if (jacket and jacket->isSuitPiece()) return true;

    auto shirt = dynamic_cast<Shirt *>(washable);
    if (shirt and shirt->isSuitPiece()) return true;

    auto pants = dynamic_cast<Pants *>(washable);
    if (pants and pants->isSuitPiece()) return true;

    return false;
}
