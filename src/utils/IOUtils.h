#ifndef LAUNDRY_IOUTILS_H
#define LAUNDRY_IOUTILS_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class IOUtils {
public:
    static int promptNumberedChoice(const string &prompt, const vector<string> &choices) {
        int choice;
        while (true) {
            for (int i = 0; i < choices.size(); i++) {
                cout << "(" << i + 1 << ") " << choices[i] << "\n";
            }
            cout << prompt << " (1-" << choices.size() << "): ";
            if (cin >> choice and choice >= 1 and choice <= choices.size()) {
                return choice;
            } else {
                promptFail();
            }
        }
    }

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
                else cout << " (" << minValue << " <= n <= " << maxValue;
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

    static bool promptYesNo(const string &prompt) {
        char c;
        while (true) {
            cout << prompt << " (y/n): ";
            if (cin >> c and tolower(c) == 'y' or tolower(c) == 'n') {
                return tolower(c) == 'y';
            } else {
                promptFail();
            }
        }
    }

    static void promptFail() {
        cout << "\n[!] Please enter a valid choice!\n\n";
        cin.clear();
        cin.ignore(256, '\n');
    }
};

#endif //LAUNDRY_IOUTILS_H
