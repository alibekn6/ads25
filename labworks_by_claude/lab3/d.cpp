#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countInRange(vector<int>& arr, int l, int r) {
    int left = lower_bound(arr.begin(), arr.end(), l) - arr.begin();
    int right = upper_bound(arr.begin(), arr.end(), r) - arr.begin();
    return right - left;
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < q; i++) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        if (r1 < l2 || r2 < l1) {
            int count1 = countInRange(arr, l1, r1);
            int count2 = countInRange(arr, l2, r2);
            cout << count1 + count2 << "\n";
        } else {
            int minL = min(l1, l2);
            int maxR = max(r1, r2);
            cout << countInRange(arr, minL, maxR) << "\n";
        }
    }

    return 0;
}
