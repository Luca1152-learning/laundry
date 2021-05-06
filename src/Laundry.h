#ifndef LAUNDRY_LAUNDRY_H
#define LAUNDRY_LAUNDRY_H

#include <vector>
#include <iostream>
#include "washing/Washable.h"
#include "clothes/types/ClothingType.h"
#include "clothes/types/Coat.h"
#include "clothes/types/composite/Costume.h"
#include "clothes/types/Dress.h"
#include "clothes/types/Jacket.h"
#include "clothes/types/Pants.h"
#include "clothes/types/Shirt.h"
#include "clothes/types/Windbreaker.h"
#include "washing/Client.h"

using namespace std;

class Laundry {
public:
    void addClient(const Client &client) {
        m_clients.push_back(client);
    }

private:
    vector<const Washable *> m_clothesToWash, m_clothesToWring, m_clothesToDry, m_clothesToIron, m_clothesCleaned;
    vector<Client> m_clients;
    int m_latestClientId = 0;
};

#endif //LAUNDRY_LAUNDRY_H
