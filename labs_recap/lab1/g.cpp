// Vanya and Primes 2

#include <iostream>
using namespace std;

bool isPrime(int number) {
    if (number <= 1) return false;
    if (number == 2) return true;
    if (number % 2 == 0) return false;

    for (int i = 3; i * i <= number; i += 2) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int getNthPrime(int n) {
    if (n == 1) {
        return 2;
    }
    
    int prime_count = 1;
    int current_num = 1;

    while (prime_count < n) {
        current_num += 2;
        if (isPrime(current_num)) {
            prime_count++;
        }
    }

    return current_num;
}

int main() {
    int n;
    cin >> n;

    int prime_index = getNthPrime(n);
    
    int super_prime = getNthPrime(prime_index);

    cout << super_prime << "\n";

    return 0;
}