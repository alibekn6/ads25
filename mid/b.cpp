#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main () {

    int n, k;
    cin >> n >> k;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        
        minHeap.push(num);
        
        if (minHeap.size() > k) {
            minHeap.pop();
        }
        
        if (minHeap.size() < k) {
            cout << "Bocchi" << endl;
        } else {
            cout << minHeap.top() << endl;
        }
    }

    return 0;
}