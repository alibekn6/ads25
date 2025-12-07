#include <iostream>
using namespace std;


int main() {

    int n;
    cin >> n;


    // 5
    // 2 5 4 2 8
    
    // 2 + 5 + 4 + 2 + 8 = 21
    
    // min 2
    // 3 * 2 + 21 = 27;

    vector<long long> d(n);

    long long sum = 0;
    long long minDucks = LLONG_MAX;

    for (int i = 0; i < n; i++) {
        cin >> d[i];
        sum += d[i];
        minDucks = min(minDucks, d[i]);
    }

    long long totalcost = (n - 2) * minDucks + sum;


    return 0;
}