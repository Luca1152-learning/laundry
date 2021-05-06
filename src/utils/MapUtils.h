#ifndef LAUNDRY_MAPUTILS_H
#define LAUNDRY_MAPUTILS_H

#include <vector>
#include <map>

using namespace std;

class MapUtils {
public:
    template<class A, class B, class C>
    static vector<A> getKeys(const map<A, B, C> &map) {
        vector<A> keys(map.size());
        int currentIndex = 0;
        for (auto &item:map) {
            keys[currentIndex++] = item.first;
        }
        return keys;
    }
};

#endif //LAUNDRY_MAPUTILS_H
