#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);


    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;
    cin >> k;

    int minDistance = abs(nums[0] - k);
    int index = 0;
    
    for (int i = 1; i < n; i++) {
        int currentDistance = abs(nums[i] - k);

        if (currentDistance < minDistance) {
            minDistance = currentDistance;
            index = i;
        }
    }
    cout << index;

    return 0;
}