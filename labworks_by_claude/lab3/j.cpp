#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canSteal(vector<long long>& bags, long long h, long long k) {
    long long hoursNeeded = 0;

    for (int i = 0; i < bags.size(); i++) {
        hoursNeeded += (bags[i] + k - 1) / k;
        if (hoursNeeded > h) {
            return false;
        }
    }

    return hoursNeeded <= h;
}

int main() {
    int n;
    long long h;
    cin >> n >> h;

    vector<long long> bags(n);
    long long maxBars = 0;

    for (int i = 0; i < n; i++) {
        cin >> bags[i];
        maxBars = max(maxBars, bags[i]);
    }

    long long left = 1, right = maxBars;
    long long result = maxBars;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        if (canSteal(bags, h, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << result << "\n";
    return 0;
}
