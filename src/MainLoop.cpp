#include "MainLoop.h"

// Public
void MainLoop::run() {
    while (promptCommand());
}

// Private
bool MainLoop::promptCommand() {
    vector<string> choices = {"Add client"};

    bool laundryHasClients = not m_laundry.getClients().empty();
    if (laundryHasClients) {
        if (m_laundry.getClients().size() == 1) {
            choices.emplace_back("View client's clothes' history");
        } else {
            choices.emplace_back("View clients' clothes' history");
        }
    }

    int uncompletedClientOrders = m_laundry.getClients().size() - m_oldClients.size();
    bool areUncompletedOrders = uncompletedClientOrders > 0;
    if (uncompletedClientOrders) {
        if (uncompletedClientOrders == 1) {
            choices.emplace_back(
                    "Force run all machines (" + to_string(uncompletedClientOrders) + " uncompleted client order)"
            );
        } else {
            choices.emplace_back(
                    "Force run all machines (" + to_string(uncompletedClientOrders) + " uncompleted client orders)"
            );
        }
    }

    choices.emplace_back("Exit program");

    int commandChoice = IOUtils::promptNumberedChoice("Operation to perform", choices);

    if (commandChoice == 1) {
        cout << "\n";
        Client client;
        while (promptClientOrder(client));
        cout << "\n";

        m_laundry.addClient(client);
        m_laundry.runMachines(true);
        updateCompletedClientOrdersAndPrint();

        return true;
    } else if (laundryHasClients and commandChoice == 2) {
        promptViewClientsClothesHistory();
        return true;
    } else if (areUncompletedOrders and commandChoice == 2 + laundryHasClients) {
        m_laundry.runMachines(false);
        cout << "\n[!] Force run all machines.\n\n";
        updateCompletedClientOrdersAndPrint();
        return true;
    } else if (commandChoice == 2 + laundryHasClients + uncompletedClientOrders) {
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

    // Handle suits
    if (clothingType == ClothingType::SUIT) {
        promptAddSuitPieceToClient(client);
        return;
    }

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
            {"Coat", "Dress", "Jacket", "Pants", "Shirt", "Suit", "Windbreaker"}
    );

    if (clothingChoice == 1) return ClothingType::COAT;
    else if (clothingChoice == 2) return ClothingType::DRESS;
    else if (clothingChoice == 3) return ClothingType::JACKET;
    else if (clothingChoice == 4) return ClothingType::PANTS;
    else if (clothingChoice == 5) return ClothingType::SHIRT;
    else if (clothingChoice == 6) return ClothingType::SUIT;
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

void MainLoop::promptAddSuitPieceToClient(Client &client) {
    // Suits count
    int itemsCount = promptItemsCount();

    // Shirt info
    cout << "\n";
    if (itemsCount == 1) {
        cout << "[!] Enter the shirt's info.\n";
    } else {
        cout << "[!] Enter the shirts' info.\n";
    }
    double shirtWeight = promptWeight(itemsCount);
    bool shirtHasDarkColor = promptHasDarkColor(itemsCount);
    double shirtMinWashingTemperature, shirtMaxWashingTemperature;
    tie(shirtMinWashingTemperature, shirtMaxWashingTemperature) = promptWashingTemperatureRange(itemsCount);
    cout << "\n";

    // Jacket info
    if (itemsCount == 1) {
        cout << "[!] Enter the jacket's info.\n";
    } else {
        cout << "[!] Enter the jackets' info.\n";
    }
    double jacketWeight = promptWeight(itemsCount);
    bool jacketHasDarkColor = promptHasDarkColor(itemsCount);
    double jacketMinWashingTemperature, jacketMaxWashingTemperature;
    tie(jacketMinWashingTemperature, jacketMaxWashingTemperature) = promptWashingTemperatureRange(itemsCount);
    cout << "\n";

    // Pants info
    cout << "[!] Enter the pants' info.\n";
    double pantsWeight = promptWeight(itemsCount);
    bool pantsHaveDarkColor = promptHasDarkColor(itemsCount);
    double pantsMinWashingTemperature, pantsMaxWashingTemperature;
    tie(pantsMinWashingTemperature, pantsMaxWashingTemperature) = promptWashingTemperatureRange(itemsCount);
    cout << "\n";

    // Add the items
    client.addClothingItems(
            ClothingType::SHIRT, shirtWeight, shirtHasDarkColor,
            shirtMinWashingTemperature, shirtMaxWashingTemperature, itemsCount, true
    );
    client.addClothingItems(
            ClothingType::JACKET, jacketWeight, jacketHasDarkColor,
            jacketMinWashingTemperature, jacketMaxWashingTemperature, itemsCount, true
    );
    client.addClothingItems(
            ClothingType::PANTS, pantsWeight, pantsHaveDarkColor,
            pantsMinWashingTemperature, pantsMaxWashingTemperature, itemsCount, true
    );
}

void MainLoop::promptViewClientsClothesHistory() {
    cout << "\n";

    if (m_laundry.getClients().size() == 1) {
        while (promptViewClothesHistoryForClient(m_laundry.getClients()[0]));
        return;
    } else {
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

void MainLoop::updateCompletedClientOrdersAndPrint() {
    bool newOrderCompleted = false;
    for (auto &client: m_laundry.getClients()) {
        // If a new client's clothes were all completely washed

        double usedMachineTime = client.getClothesTotalTimeSpentInMachines() / client.getClothingItems().size();
        stringstream usedMachineTimeSS;
        usedMachineTimeSS << fixed << setprecision(1) << usedMachineTime;

        if (find(m_oldClients.begin(), m_oldClients.end(), client) == m_oldClients.end() and
            client.didAllClothesCompleteWashingCircuit()) {
            cout << "[!] Client #" << client.getId() << "'s order was completed.\n"
                 << "[!] Detergent used: " << client.getClothesTotalDetergentUsed() << "g. "
                 << "Used machine time: " << usedMachineTimeSS.str() << " minutes\n";
            m_oldClients.push_back(client);
            newOrderCompleted = true;
        }
    }

    if (newOrderCompleted) {
        cout << "\n";
    }
}