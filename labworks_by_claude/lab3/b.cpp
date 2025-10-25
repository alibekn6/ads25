#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canDivide(vector<long long>& arr, int k, long long maxSum) {
    int blocks = 1;
    long long currentSum = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > maxSum) {
            return false;
        }

        if (currentSum + arr[i] > maxSum) {
            blocks++;
            currentSum = arr[i];
        } else {
            currentSum += arr[i];
        }
    }

    return blocks <= k;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> arr(n);
    long long maxElement = 0, totalSum = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        maxElement = max(maxElement, arr[i]);
        totalSum += arr[i];
    }

    long long left = maxElement, right = totalSum;
    long long result = totalSum;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        if (canDivide(arr, k, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << result << "\n";
    return 0;
}
