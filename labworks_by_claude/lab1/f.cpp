#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;

    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> primes;
    int num = 2;

    while (primes.size() < n) {
        if (isPrime(num)) {
            primes.push_back(num);
        }
        num++;
    }

    cout << primes[n - 1] << "\n";

    return 0;
}
