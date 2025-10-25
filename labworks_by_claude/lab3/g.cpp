#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canDeliver(vector<int>& children, int f, int capacity) {
    int flights = 0;

    for (int i = 0; i < children.size(); i++) {
        flights += (children[i] + capacity - 1) / capacity;
    }

    return flights <= f;
}

int main() {
    int n, f;
    cin >> n >> f;

    vector<int> children(n);
    int maxChildren = 0;

    for (int i = 0; i < n; i++) {
        cin >> children[i];
        maxChildren = max(maxChildren, children[i]);
    }

    int left = 1, right = maxChildren;
    int result = maxChildren;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (canDeliver(children, f, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << result << "\n";
    return 0;
}
