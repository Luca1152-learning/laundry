#include "MainLoop.h"

// Public
void MainLoop::run() {
    while (promptCommand());
}

// Private
bool MainLoop::promptCommand() {
    int commandChoice = IOUtils::promptNumberedChoice(
            "Operation to perform",
            {"Add client", "View clothes' history", "Exit program"}
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
        promptViewClothesHistory();
        return true;
    } else if (commandChoice == 3) {
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

void MainLoop::promptViewClothesHistory() {
    cout << "\n";
    if (m_laundry.getClients().empty()) {
        cout << "[!] No clients were added yet.\n\n";
        return;
    }

    int clientId = IOUtils::promptNumber(
            "Enter the client's id whose clothes' history you want to see",
            1, (int) (m_laundry.getClients().size())
    );

    for (auto &client: m_laundry.getClients()) {
        if (client.getId() == clientId) {
            while (promptViewClothesHistoryForClient(client));
            return;
        }
    }

    throw runtime_error("The client wasn't found. This wasn't expected.");
}

bool MainLoop::promptViewClothesHistoryForClient(const Client &client) {
    vector<Washable *> clothingItems = client.getClothingItems();
    vector<string> choices;
    for (auto &item: clothingItems) {
        double minWashingTemperature = item->getMinWashingTemperature();
        double maxWashingTemperature = item->getMaxWashingTemperature();
        string clothingType = ClothingTypeUtils::toString(WashableUtils::getClothingType(item));

        auto clothing = dynamic_cast<Clothing *>(item);
        double weight = clothing->getWeight();
        int itemId = clothing->getId();
        bool hasDarkColor = clothing->hasDarkColor();


        stringstream weightSS, minWashingTemperatureSS, maxWashingTemperatureSS;
        weightSS << fixed << setprecision(1) << weight;
        minWashingTemperatureSS << fixed << setprecision(1) << minWashingTemperature;
        maxWashingTemperatureSS << fixed << setprecision(1) << maxWashingTemperature;

        string itemChoiceString = clothingType + " (id #" + to_string(itemId) + ") | " +
                                  weightSS.str() + " kg";
        if (hasDarkColor) {
            itemChoiceString += " | dark colored";
        }
        itemChoiceString += " | washing temperature: " + minWashingTemperatureSS.str() + "-" +
                            maxWashingTemperatureSS.str();

        choices.push_back(itemChoiceString);
    }
    choices.emplace_back("Exit");

    int commandChoice = IOUtils::promptNumberedChoice("Item choice", choices);
    if (commandChoice == choices.size()) {
        // Exit
        cout << "\n";
        return false;
    } else {
        cout << "\n";
        clothingItems[commandChoice - 1]->printHistory();
        cout << "\n";

        // Prompt for ENTER before showing the menu again
        cout << "[!] Press ENTER to continue";
        cin.sync();
        cin.ignore(256, '\n');
        cin.get();
        cout << "\n";

        return true;
    }
}
