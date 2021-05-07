#ifndef LAUNDRY_CLIENT_H
#define LAUNDRY_CLIENT_H

#include <vector>
#include "washing/Washable.h"
#include "../clothes/types/ClothingType.h"
#include "../utils/WashableUtils.h"

using namespace std;

class Client {
public:
    explicit Client();

    int getId() const;

    void addClothingItem(
            ClothingType clothingType, double weight, bool hasDarkColor,
            double minWashingTemperature, double maxWashingTemperature
    );

    void addClothingItems(
            ClothingType clothingType, double weight, bool hasDarkColor,
            double minWashingTemperature, double maxWashingTemperature,
            int itemsCount
    );

    const vector<Washable *> &getClothingItems() const;

    double getClothesTotalTimeSpentInMachines() const;

    double getClothesTotalDetergentUsed() const;

    bool didAllClothesCompleteWashingCircuit() const;

    // Operators
    bool operator==(const Client &other) const;

    bool operator!=(const Client &other) const;

private:
    const int m_id;
    static int lastId;
    vector<Washable *> m_clothes;
};

#endif //LAUNDRY_CLIENT_H
