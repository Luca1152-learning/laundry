#ifndef LAUNDRY_MAINLOOP_H
#define LAUNDRY_MAINLOOP_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include <map>
#include "laundry/Laundry.h"
#include "utils/IOUtils.h"

using namespace std;

class MainLoop {
public:
    void run();

private:
    Laundry m_laundry;

    bool promptCommand();

    // Clothes orders
    static bool promptClientOrder(Client &client);

    static void promptAddClothingItemToClient(Client &client);

    static ClothingType promptClothingType();

    static int promptItemsCount();

    static double promptWeight(int itemsCount);

    static bool promptHasDarkColor(int itemsCount);

    static pair<double, double> promptWashingTemperatureRange(int itemsCount);

    // View history
    void promptViewClientsClothesHistory();

    bool promptViewClothesHistoryForClient(const Client &client);
};

#endif //LAUNDRY_MAINLOOP_H
