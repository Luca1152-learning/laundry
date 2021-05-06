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
    Laundry() {
        addMachines();
    }

    void addClient(const Client &client) {
        m_clients.push_back(client);

        const vector<Washable *> &clientItems = client.getClothingItems();
        for (auto &item: clientItems) {
            m_washingQueue.push(item);
        }
    }

    void runMachines(bool onlyIfHalfFull = true) {
        runWashingMachines(onlyIfHalfFull);
        runWringerMachines(onlyIfHalfFull);
        runDryingMachines(onlyIfHalfFull);
        runIroningMachines();
    }

private:
    vector<Client> m_clients;

    // Cleaning
    queue<Washable *> m_washingQueue, m_wringingQueue, m_dryingQueue, m_ironingQueue;

    // Machines
    vector<WashingMachine> m_washingMachines;
    vector<WringerMachine> m_wringerMachines;
    vector<DryingMachine> m_dryingMachines;
    vector<IroningMachine> m_ironingMachines;

    void addMachines() {
        // Washing machines
        m_washingMachines.emplace_back(150, 45, true);
        m_washingMachines.emplace_back(150, 45, true);
        m_washingMachines.emplace_back(120, 45, false);
        m_washingMachines.emplace_back(100, 60, false);
        m_washingMachines.emplace_back(50, 45, false);
        m_washingMachines.emplace_back(50, 60, false);
        m_washingMachines.emplace_back(50, 60, false);

        // Wringer machines
        m_wringerMachines.emplace_back(150, 10);
        m_wringerMachines.emplace_back(150, 10);
        m_wringerMachines.emplace_back(100, 10);
        m_wringerMachines.emplace_back(100, 10);
        m_wringerMachines.emplace_back(100, 10);
        m_wringerMachines.emplace_back(50, 10);
        m_wringerMachines.emplace_back(50, 10);

        // Drying machines
        m_dryingMachines.emplace_back(100, 10);
        m_dryingMachines.emplace_back(50, 10);
        m_dryingMachines.emplace_back(50, 10);
        m_dryingMachines.emplace_back(50, 10);

        // Ironing machines
        const int IRONING_MACHINES_COUNT = 25;
        for (int i = 0; i < IRONING_MACHINES_COUNT; i++) {
            m_ironingMachines.emplace_back();
        }
    }

    void runWashingMachines(bool onlyIfHalfFull) {
        while (true) {
            bool didQueueItems = queueWashingMachines();
            if (didQueueItems) {
                bool didRunMachines = startWashingMachines(onlyIfHalfFull);
                if (not didRunMachines) {
                    break;
                }
            } else {
                break;
            }
        }
    }

    bool queueWashingMachines() {
        bool didQueueItems = false;
        for (auto &machine: m_washingMachines) {
            while (not m_washingQueue.empty() and machine.canAddItemToQueue(m_washingQueue.front())) {
                machine.queueItem(m_washingQueue.front());
                m_wringingQueue.push(m_washingQueue.front());
                m_washingQueue.pop();

                didQueueItems = true;
            }
        }
        return didQueueItems;
    }

    bool startWashingMachines(bool onlyIfHalfFull) {
        bool didRunMachines = false;
        for (auto &machine: m_washingMachines) {
            if (onlyIfHalfFull) {
                if (machine.isAtLeastHalfFull()) {
                    machine.run();
                    didRunMachines = true;
                }
            } else {
                machine.run();
                didRunMachines = true;
            }
        }
        return didRunMachines;
    }

    void runWringerMachines(bool onlyIfHalfFull) {
    }

    void runDryingMachines(bool onlyIfHalfFull) {
    }

    void runIroningMachines() {
    }
};

#endif //LAUNDRY_LAUNDRY_H
