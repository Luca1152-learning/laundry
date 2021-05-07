#include "Client.h"

// Public
Client::Client() : m_id(++lastId) {}

int Client::getId() const {
    return m_id;
}

void Client::addClothingItem(
        ClothingType clothingType, double weight, bool hasDarkColor,
        double minWashingTemperature, double maxWashingTemperature) {
    m_clothes.push_back(WashableUtils::makeClothingItem(
            clothingType, weight, hasDarkColor, minWashingTemperature, maxWashingTemperature
    ));
}

void Client::addClothingItems(ClothingType clothingType, double weight, bool hasDarkColor, double minWashingTemperature,
                              double maxWashingTemperature, int itemsCount) {
    for (int i = 0; i < itemsCount; i++) {
        addClothingItem(clothingType, weight, hasDarkColor, minWashingTemperature, maxWashingTemperature);
    }
}

const vector<Washable *> &Client::getClothingItems() const {
    return m_clothes;
}

// Private
int Client::lastId = 0;