#ifndef LAUNDRY_IOUTILS_H
#define LAUNDRY_IOUTILS_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class IOUtils {
public:
    static int promptNumberedChoice(const string &prompt, const vector<string> &choices);

    template<class T>
    static T promptNumber(const string &prompt, T minValue = -1, T maxValue = -1) {
        if (minValue > maxValue and minValue != -1 and maxValue != -1) {
            throw runtime_error("The minValue should be smaller than maxValue!");
        }

        T value;
        while (true) {
            cout << prompt;
            if (minValue != -1) {
                if (maxValue == -1) cout << " (n >= " << minValue << ")";
                else cout << " (" << minValue << " <= n <= " << maxValue << ")";
            } else if (maxValue != -1) {
                cout << " (n <= " << maxValue << ")";
            }
            cout << ": ";

            if (cin >> value) {
                if ((minValue != -1 and value < minValue) or (maxValue != -1 and value > maxValue)) {
                    promptFail();
                } else {
                    return value;
                }
            } else {
                promptFail();
            }
        }
    }

    static bool promptYesNo(const string &prompt);

    static void promptFail();
};

#endif //LAUNDRY_IOUTILS_H
