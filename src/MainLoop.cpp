#include "MainLoop.h"

// Public
void MainLoop::run() {
    while (promptCommand());
}

// Private
bool MainLoop::promptCommand() {
    int commandChoice = IOUtils::promptNumberedChoice(
            "Operation to perform",
            {"Add client", "Exit program"}
    );

    if (commandChoice == 1) {
        cout << "\n";
        Client client;
        while (promptClientOrder(client));
        cout << "\n";

        m_laundry.addClient(client);
        m_laundry.runMachines(false);

        return true;
    } else if (commandChoice == 2) {
        return false;
    } else {
        throw runtime_error("This command choice isn't being handled.");
    }
}

bool MainLoop::promptClientOrder(Client &client) {
    cout << "[Client #" << client.getId() << "]\n";
    int commandChoice = IOUtils::promptNumberedChoice(
            "Operation to perform",
            {"Add clothing item(s)", "Exit order"}
    );

    if (commandChoice == 1) {
        promptAddClothingItemToClient(client);
        return true;
    } else if (commandChoice == 2) {
        return false;
    } else {
        throw runtime_error("This command choice isn't being handled.");
    }
}

void MainLoop::promptAddClothingItemToClient(Client &client) {
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

ClothingType MainLoop::promptClothingType() {
    cout << "\n";
    int clothingChoice = IOUtils::promptNumberedChoice(
            "Clothing type to add",
            {"Coat", "Costume", "Dress", "Jacket", "Pants", "Shirt", "Windbreaker"}
    );

    if (clothingChoice == 1) return ClothingType::COAT;
    else if (clothingChoice == 2) return ClothingType::COSTUME;
    else if (clothingChoice == 3) return ClothingType::DRESS;
    else if (clothingChoice == 4) return ClothingType::JACKET;
    else if (clothingChoice == 5) return ClothingType::PANTS;
    else if (clothingChoice == 6) return ClothingType::SHIRT;
    else if (clothingChoice == 7) return ClothingType::WINDBREAKER;
    else throw runtime_error("This clothing type isn't being handled.");
}

int MainLoop::promptItemsCount() {
    return IOUtils::promptNumber("Items count", 1);
}

double MainLoop::promptWeight(int itemsCount) {
    return IOUtils::promptNumber(
            (itemsCount == 1) ? "The item's weight in kg" : "Each item's individual weight in kg",
            0.01
    );
}

bool MainLoop::promptHasDarkColor(int itemsCount) {
    return IOUtils::promptYesNo(
            (itemsCount == 1) ? "The item has a dark color" : "The items have a dark color"
    );
}

pair<double, double> MainLoop::promptWashingTemperatureRange(int itemsCount) {
    cout << "\n";
    int rangeChoice = IOUtils::promptNumberedChoice(
            (itemsCount == 1) ? "The item requires" : "The items require",
            {"A minimum washing temperature", "A maximum washing temperature"}
    );
    cout << "\n";

    double minTemp = Washable::MIN_WASHING_TEMPERATURE, maxTemp = Washable::MAX_WASHING_TEMPERATURE;
    if (rangeChoice == 1) {
        minTemp = IOUtils::promptNumber("Minimum washing temperature:",
                                        Washable::MIN_WASHING_TEMPERATURE, Washable::MAX_WASHING_TEMPERATURE);
    } else if (rangeChoice == 2) {
        maxTemp = IOUtils::promptNumber("Maximum washing temperature",
                                        Washable::MIN_WASHING_TEMPERATURE, Washable::MAX_WASHING_TEMPERATURE);
    } else {
        throw runtime_error("This range choice isn't being handled.");
    }

    return {minTemp, maxTemp};
}

