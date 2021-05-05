#ifndef LAUNDRY_MAINLOOP_H
#define LAUNDRY_MAINLOOP_H

#include <iostream>
#include <map>
#include "Laundry.h"
#include "utils/IOUtils.h"
#include "utils/MapUtils.h"

using namespace std;

class MainLoop {
public:
    void run() {
        while (promptCommand());
    }

private:
    Laundry m_laundry;

    bool promptCommand() {
        map<string, int> choices = {
                {"Add clothing item(s)", 1},
                {"Exit",                 2}
        };
        int commandChoice = IOUtils::promptNumberedChoice(
                "Operation to perform",
                MapUtils::getKeys(choices)
        );

        if (commandChoice == choices["Add clothing item(s)"]) {
            promptAddClothingItem();
            return true;
        } else if (commandChoice == choices["Exit"]) {
            return false;
        } else {
            throw runtime_error("This command choice isn't being handled.");
        }
    }

    void promptAddClothingItem() {
        auto clothingType = promptClothingType();
        cout << "\n";
        auto itemsCount = promptItemsCount();
        auto weight = promptWeight(itemsCount);
        auto hasDarkColor = promptHasDarkColor(itemsCount);
        addClothingItemsToLaundry(clothingType, itemsCount, weight, hasDarkColor);
        cout << "\n";
    }

    static ClothingType promptClothingType() {
        map<string, int> choices = {
                {"Coat",        1},
                {"Costume",     2},
                {"Dress",       3},
                {"Jacket",      4},
                {"Pants",       5},
                {"Shirt",       6},
                {"Windbreaker", 7}
        };
        cout << "\n";
        int clothingChoice = IOUtils::promptNumberedChoice(
                "Clothing type to add",
                MapUtils::getKeys(choices)
        );

        if (clothingChoice == choices["Coat"]) return ClothingType::COAT;
        else if (clothingChoice == choices["Costume"]) return ClothingType::COSTUME;
        else if (clothingChoice == choices["Dress"]) return ClothingType::DRESS;
        else if (clothingChoice == choices["Jacket"]) return ClothingType::JACKET;
        else if (clothingChoice == choices["Pants"]) return ClothingType::PANTS;
        else if (clothingChoice == choices["Shirt"]) return ClothingType::SHIRT;
        else if (clothingChoice == choices["Windbreaker"]) return ClothingType::WINDBREAKER;
        else throw runtime_error("This clothing type isn't being handled.");
    }

    static int promptItemsCount() {
        return IOUtils::promptNumber("Items count", 1);
    }

    static double promptWeight(int itemsCount) {
        return IOUtils::promptNumber(
                (itemsCount == 1) ? "The item's weight" : "Each item's individual weight",
                0.01
        );
    }

    static bool promptHasDarkColor(int itemsCount) {
        return IOUtils::promptYesNo(
                (itemsCount == 1) ? "The item has a dark color" : "The items have a dark color"
        );
    }

    void addClothingItemsToLaundry(ClothingType clothingType, int itemsCount, double weight, bool hasDarkColor) {
        for (int i = 0; i < itemsCount; i++) {
            m_laundry.addClothingItemToWash(clothingType, weight, hasDarkColor);
        }
    }
};

#endif //LAUNDRY_MAINLOOP_H
