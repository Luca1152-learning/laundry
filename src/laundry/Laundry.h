#ifndef LAUNDRY_LAUNDRY_H
#define LAUNDRY_LAUNDRY_H

#include <queue>
#include <vector>
#include <iostream>
#include "../laundry/washing/Washable.h"
#include "../clothes/types/ClothingType.h"
#include "../clothes/types/Coat.h"
#include "../clothes/types/composite/Costume.h"
#include "../clothes/types/Dress.h"
#include "../clothes/types/Jacket.h"
#include "../clothes/types/Pants.h"
#include "../clothes/types/Shirt.h"
#include "../clothes/types/Windbreaker.h"
#include "Client.h"
#include "washing/machines/WashingMachine.h"
#include "washing/machines/WringerMachine.h"
#include "washing/machines/DryingMachine.h"
#include "washing/machines/IroningMachine.h"

using namespace std;

class Laundry {
public:
    Laundry();

    void addClient(const Client &client);

    void runMachines(bool onlyIfHalfFull = true);

    const vector<Client> &getClients();

private:
    vector<Client> m_clients;

    // Cleaning
    queue<Washable *> m_washingQueue, m_wringingQueue, m_dryingQueue, m_ironingQueue;

    // Machines
    vector<WashingMachine> m_washingMachines;
    vector<WringerMachine> m_wringerMachines;
    vector<DryingMachine> m_dryingMachines;
    vector<IroningMachine> m_ironingMachines;

    void addMachines();

    // Washing machines
    void runWashingMachines(bool onlyIfHalfFull);

    bool queueWashingMachines();

    bool startWashingMachines(bool onlyIfHalfFull);

    // Wringer machines
    void runWringerMachines(bool onlyIfHalfFull);

    bool queueWringerMachines();

    bool startWringerMachines(bool onlyIfHalfFull);

    // Drying machines
    void runDryingMachines(bool onlyIfHalfFull);

    bool queueDryingMachines();

    bool startDryingMachines(bool onlyIfHalfFull);

    // Ironing machines
    void runIroningMachines();

    bool queueIroningMachines();

    void startIroningMachines();
};

#endif //LAUNDRY_LAUNDRY_H
