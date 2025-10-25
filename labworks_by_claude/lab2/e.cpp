#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> names;
    string prevName = "";

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        if (name != prevName) {
            names.push_back(name);
            prevName = name;
        }
    }

    sort(names.begin(), names.end());

    cout << "All in all: " << names.size() << "\n";
    cout << "Students:\n";
    for (const string& name : names) {
        cout << name << "\n";
    }

    return 0;
}
