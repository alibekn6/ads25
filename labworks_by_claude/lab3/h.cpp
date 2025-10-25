#include <iostream>
#include <vector>
using namespace std;

int binarySearchBlock(vector<long long>& prefix, int target) {
    int left = 0, right = prefix.size() - 1;
    int result = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (prefix[mid] >= target) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result + 1;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> prefix(n);
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        int lines;
        cin >> lines;
        sum += lines;
        prefix[i] = sum;
    }

    for (int i = 0; i < m; i++) {
        int lineNum;
        cin >> lineNum;
        cout << binarySearchBlock(prefix, lineNum) << "\n";
    }

    return 0;
}
