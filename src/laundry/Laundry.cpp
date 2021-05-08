#include "Laundry.h"

// Public
Laundry::Laundry() {
    addMachines();
}

void Laundry::addClient(const Client &client) {
    m_clients.push_back(client);

    const vector<Washable *> &clientItems = client.getClothingItems();
    for (auto &item: clientItems) {
        m_washingQueue.push(item);
    }
}

void Laundry::runMachines(bool onlyIfHalfFull) {
    runWashingMachines(onlyIfHalfFull);
    runWringerMachines(onlyIfHalfFull);
    runDryingMachines(onlyIfHalfFull);
    runIroningMachines();
}

const vector<Client> &Laundry::getClients() const {
    return m_clients;
}

// Private
void Laundry::addMachines() {
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

// Washing machines
void Laundry::runWashingMachines(bool onlyIfHalfFull) {
    while (true) {
        bool didQueueItems = queueWashingMachines();
        if (didQueueItems or not onlyIfHalfFull) {
            bool didRunMachines = startWashingMachines(onlyIfHalfFull);
            if (not didRunMachines) {
                break;
            }
        } else {
            break;
        }
    }
}

bool Laundry::queueWashingMachines() {
    bool didQueueItems = false;
    int itemsToQueue = m_washingQueue.size();

    while (itemsToQueue) {
        Washable *topItem = m_washingQueue.front();
        auto topClothingItem = dynamic_cast<Clothing *>(topItem);

        bool didQueueItem = false;

        for (auto &machine: m_washingMachines) {
            // Don't wash light color clothes and dark color clothes together
            if ((topClothingItem->hasDarkColor() and machine.hasLightColoredClothesInQueue())
                or (not topClothingItem->hasDarkColor() and machine.hasDarkColoredClothesInQueue())) {
                continue;
            }
            // Don't wash heavy clothes in non-special washing machines
            if (topClothingItem->isHeavy() and not machine.canWashHeavyClothes()) {
                continue;
            }
            // Don't wash non-heavy clothes in special washing machines (as to be more efficient)
            if (not topClothingItem->isHeavy() and machine.canWashHeavyClothes()) {
                continue;
            }
            // Don't wash clothes in inappropriate temperatures
            if (machine.isTemperatureSet() and (topItem->getMinWashingTemperature() > machine.getTemperature() or
                                                topItem->getMaxWashingTemperature() < machine.getTemperature())) {
                continue;
            }

            if (machine.canAddItemToQueue(topItem)) {
                machine.queueItem(topItem);
                if (not machine.isTemperatureSet()) {
                    machine.setTemperature(
                            (topItem->getMinWashingTemperature() + topItem->getMaxWashingTemperature()) / 2.0
                    );
                }

                // Queue the next step
                if (topItem->mustBeWringed()) {
                    m_wringingQueue.push(topItem);
                } else {
                    m_dryingQueue.push(topItem);
                }
                m_washingQueue.pop();

                didQueueItem = true;
                didQueueItems = true;
                break;
            }
        }

        // An item couldn't be queued, which means that there was no available washing machine
        // for it. Thus, it should be rescheduled for the next run.
        if (not didQueueItem) {
            m_washingQueue.push(topItem);
            m_washingQueue.pop();
        }

        itemsToQueue--;
    }
    return didQueueItems;
}

bool Laundry::startWashingMachines(bool onlyIfHalfFull) {
    bool didRunMachines = false;
    for (auto &machine: m_washingMachines) {
        if (onlyIfHalfFull) {
            if (machine.isAtLeastHalfFull()) {
                machine.run();
                didRunMachines = true;
            }
        } else {
            machine.run();
            didRunMachines = false;
        }
    }
    return didRunMachines;
}

// Wringer machines
void Laundry::runWringerMachines(bool onlyIfHalfFull) {
    while (true) {
        bool didQueueItems = queueWringerMachines();
        if (didQueueItems or not onlyIfHalfFull) {
            bool didRunMachines = startWringerMachines(onlyIfHalfFull);
            if (not didRunMachines) {
                break;
            }
        } else {
            break;
        }
    }
}

bool Laundry::queueWringerMachines() {
    bool didQueueItems = false;
    for (auto &machine: m_wringerMachines) {
        while (not m_wringingQueue.empty() and machine.canAddItemToQueue(m_wringingQueue.front())) {
            machine.queueItem(m_wringingQueue.front());
            m_dryingQueue.push(m_wringingQueue.front());
            m_wringingQueue.pop();

            didQueueItems = true;
        }
    }
    return didQueueItems;
}

bool Laundry::startWringerMachines(bool onlyIfHalfFull) {
    bool didRunMachines = false;
    for (auto &machine: m_wringerMachines) {
        if (onlyIfHalfFull) {
            if (machine.isAtLeastHalfFull()) {
                machine.run();
                didRunMachines = true;
            }
        } else {
            machine.run();
            didRunMachines = false;
        }
    }
    return didRunMachines;
}

// Drying machines
void Laundry::runDryingMachines(bool onlyIfHalfFull) {
    while (true) {
        bool didQueueItems = queueDryingMachines();
        if (didQueueItems or not onlyIfHalfFull) {
            bool didRunMachines = startDryingMachines(onlyIfHalfFull);
            if (not didRunMachines) {
                break;
            }
        } else {
            break;
        }
    }
}

bool Laundry::queueDryingMachines() {
    bool didQueueItems = false;
    for (auto &machine: m_dryingMachines) {
        while (not m_dryingQueue.empty() and machine.canAddItemToQueue(m_dryingQueue.front())) {
            Washable *item = m_dryingQueue.front();

            // Queue the machine
            machine.queueItem(item);

            // Queue the next step
            if (item->mustBeIroned()) {
                m_ironingQueue.push(item);
            }
            m_dryingQueue.pop();

            didQueueItems = true;
        }
    }
    return didQueueItems;
}

bool Laundry::startDryingMachines(bool onlyIfHalfFull) {
    bool didRunMachines = false;
    for (auto &machine: m_dryingMachines) {
        if (onlyIfHalfFull) {
            if (machine.isAtLeastHalfFull()) {
                machine.run();
                didRunMachines = true;
            }
        } else {
            machine.run();
            didRunMachines = false;
        }
    }
    return didRunMachines;
}

// Ironing machines
void Laundry::runIroningMachines() {
    while (true) {
        bool didQueueItems = queueIroningMachines();
        if (didQueueItems) {
            startIroningMachines();
        } else {
            break;
        }
    }
}

bool Laundry::queueIroningMachines() {
    bool didQueueItems = false;
    for (auto &machine: m_ironingMachines) {
        while (not m_ironingQueue.empty() and machine.canAddItemToQueue(m_ironingQueue.front())) {
            Washable *item = m_ironingQueue.front();

            machine.queueItem(item);
            m_ironingQueue.pop();

            didQueueItems = true;
        }
    }
    return didQueueItems;
}

void Laundry::startIroningMachines() {
    for (auto &machine: m_ironingMachines) {
        machine.run();
    }
}