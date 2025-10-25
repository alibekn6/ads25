#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, int> freq;
    int maxFreq = 0;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        freq[num]++;
        maxFreq = max(maxFreq, freq[num]);
    }

    vector<int> modes;
    for (auto& p : freq) {
        if (p.second == maxFreq) {
            modes.push_back(p.first);
        }
    }

    sort(modes.begin(), modes.end(), greater<int>());

    for (size_t i = 0; i < modes.size(); i++) {
        cout << modes[i];
        if (i < modes.size() - 1) cout << " ";
    }
    cout << "\n";

    return 0;
}
