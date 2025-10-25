#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> powers(n);
    for (int i = 0; i < n; i++) {
        cin >> powers[i];
    }

    sort(powers.begin(), powers.end());

    vector<long long> prefixSum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefixSum[i + 1] = prefixSum[i] + powers[i];
    }

    int p;
    cin >> p;

    for (int i = 0; i < p; i++) {
        int markPower;
        cin >> markPower;

        int left = 0, right = n;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (powers[mid - 1] <= markPower) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }

        cout << left << " " << prefixSum[left] << "\n";
    }

    return 0;
}
