#include "IOUtils.h"

// Public
int IOUtils::promptNumberedChoice(const string &prompt, const vector<string> &choices) {
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

bool IOUtils::promptYesNo(const string &prompt) {
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

void IOUtils::promptFail() {
    cout << "\n[!] Please enter a valid choice!\n\n";
    cin.clear();
    cin.ignore(256, '\n');
}