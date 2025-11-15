#include <iostream>
#include <vector>
using namespace std;


int main() {

    int n, x;
    cin >> n >> x;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int left = 0, right = n - 1;

    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] >= x) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    if (result != -1) {
        cout << result + 1 << endl;
    } else {
        cout << -1 << endl;

    }


    return 0;
}