#include "Client.h"

// Public
Client::Client() : m_id(++lastId) {}

int Client::getId() const {
    return m_id;
}

void Client::addClothingItem(
        ClothingType clothingType, double weight, bool hasDarkColor,
        double minWashingTemperature, double maxWashingTemperature, bool isSuitPiece) {
    m_clothes.push_back(WashableUtils::makeClothingItem(
            clothingType, weight, hasDarkColor, minWashingTemperature, maxWashingTemperature, isSuitPiece
    ));
}

void Client::addClothingItems(ClothingType clothingType, double weight, bool hasDarkColor, double minWashingTemperature,
                              double maxWashingTemperature, int itemsCount, bool isSuitPiece) {
    for (int i = 0; i < itemsCount; i++) {
        addClothingItem(clothingType, weight, hasDarkColor, minWashingTemperature, maxWashingTemperature, isSuitPiece);
    }
}

const vector<Washable *> &Client::getClothingItems() const {
    return m_clothes;
}

double Client::getClothesTotalTimeSpentInMachines() const {
    double time = 0;
    for (auto &item: m_clothes) {
        time += item->getTimeSpentInMachines();
    }
    return time;
}

double Client::getClothesTotalDetergentUsed() const {
    double detergentQuantity = 0;
    for (auto &item: m_clothes) {
        detergentQuantity += item->getDetergentUsed();
    }
    return detergentQuantity;
}

bool Client::didAllClothesCompleteWashingCircuit() const {
    for (auto &item: m_clothes) {
        if (not item->didCompleteWashingCircuit()) {
            return false;
        }
    }
    return true;
}

// Operators
bool Client::operator==(const Client &other) const {
    return m_id == other.m_id;
}

bool Client::operator!=(const Client &other) const {
    return !(other == *this);
}


// Private
int Client::lastId = 0;