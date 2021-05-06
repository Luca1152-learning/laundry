#ifndef LAUNDRY_CLIENT_H
#define LAUNDRY_CLIENT_H

#include <vector>
#include "Washable.h"
#include "../clothes/types/ClothingType.h"
#include "../utils/WashableUtils.h"

using namespace std;

class Client {
public:
    explicit Client(int id) : m_id(id) {}

    int getId() const {
        return m_id;
    }

    void addClothingItem(
            ClothingType clothingType, double weight, bool hasDarkColor,
            double minWashingTemperature, double maxWashingTemperature
    ) {
        m_clothes.push_back(WashableUtils::makeClothingItem(
                clothingType, weight, hasDarkColor, minWashingTemperature, maxWashingTemperature
        ));
    }

    void addClothingItems(
            ClothingType clothingType, double weight, bool hasDarkColor,
            double minWashingTemperature, double maxWashingTemperature,
            int itemsCount
    ) {
        for (int i = 0; i < itemsCount; i++) {
            addClothingItem(clothingType, weight, hasDarkColor, minWashingTemperature, maxWashingTemperature);
        }
    }

    const vector<Washable *> &getClothingItems() const {
        return m_clothes;
    }

private:
    const int m_id;
    vector<Washable *> m_clothes;
};

#endif //LAUNDRY_CLIENT_H
