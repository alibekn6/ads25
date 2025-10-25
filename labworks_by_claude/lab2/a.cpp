#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    int minDist = abs(arr[0] - k);
    int result = 0;

    for (int i = 1; i < n; i++) {
        int dist = abs(arr[i] - k);
        if (dist < minDist) {
            minDist = dist;
            result = i;
        }
    }

    cout << result << "\n";
    return 0;
}
