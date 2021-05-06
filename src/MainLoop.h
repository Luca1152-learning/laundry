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
                {"Add client",   1},
                {"Exit program", 2}
        };
        int commandChoice = IOUtils::promptNumberedChoice(
                "Operation to perform",
                MapUtils::getKeys(choices)
        );

        if (commandChoice == choices["Add client"]) {
            cout << "\n";
            Client client = m_laundry.createClient();
            while (promptClientOrder(client));
            cout << "\n";

            m_laundry.addClient(client);

            return true;
        } else if (commandChoice == choices["Exit program"]) {
            return false;
        } else {
            throw runtime_error("This command choice isn't being handled.");
        }
    }

    static bool promptClientOrder(Client &client) {
        cout << "[Client #" << client.getId() << "]\n";
        map<string, int> choices = {
                {"Add clothing item(s)", 1},
                {"Exit order",           2}
        };
        int commandChoice = IOUtils::promptNumberedChoice(
                "Operation to perform",
                MapUtils::getKeys(choices)
        );

        if (commandChoice == choices["Add clothing item(s)"]) {
            promptAddClothingItemToClient(client);
            return true;
        } else if (commandChoice == choices["Exit order"]) {
            return false;
        } else {
            throw runtime_error("This command choice isn't being handled.");
        }
    }

    static void promptAddClothingItemToClient(Client &client) {
        ClothingType clothingType = promptClothingType();
        cout << "\n";
        int itemsCount = promptItemsCount();
        double weight = promptWeight(itemsCount);
        bool hasDarkColor = promptHasDarkColor(itemsCount);
        double minWashingTemperature, maxWashingTemperature;
        tie(minWashingTemperature, maxWashingTemperature) = promptWashingTemperatureRange(itemsCount);
        cout << "\n";

        client.addClothingItems(
                clothingType, weight, hasDarkColor, minWashingTemperature, maxWashingTemperature, itemsCount
        );
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
                (itemsCount == 1) ? "The item's weight in kg" : "Each item's individual weight in kg",
                0.01
        );
    }

    static bool promptHasDarkColor(int itemsCount) {
        return IOUtils::promptYesNo(
                (itemsCount == 1) ? "The item has a dark color" : "The items have a dark color"
        );
    }

    static pair<double, double> promptWashingTemperatureRange(int itemsCount) {
        map<string, int, greater<>> choices = {
                {"A minimum washing temperature", 1},
                {"A maximum washing temperature", 2},
        };
        cout << "\n";
        int rangeChoice = IOUtils::promptNumberedChoice(
                (itemsCount == 1) ? "The item requires" : "The items require",
                MapUtils::getKeys(choices)
        );
        cout << "\n";

        double minTemp = Washable::MIN_WASHING_TEMPERATURE, maxTemp = Washable::MAX_WASHING_TEMPERATURE;
        if (rangeChoice == choices["A minimum washing temperature"]) {
            minTemp = IOUtils::promptNumber("Minimum washing temperature:",
                                            Washable::MIN_WASHING_TEMPERATURE, Washable::MAX_WASHING_TEMPERATURE);
        } else if (rangeChoice == choices["A maximum washing temperature"]) {
            maxTemp = IOUtils::promptNumber("Maximum washing temperature",
                                            Washable::MIN_WASHING_TEMPERATURE, Washable::MAX_WASHING_TEMPERATURE);
        } else {
            throw runtime_error("This range choice isn't being handled.");
        }

        return {minTemp, maxTemp};
    }
};

#endif //LAUNDRY_MAINLOOP_H
