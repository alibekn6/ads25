#include <iostream>

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;

    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
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
    std::cin >> n;

    int prime_index = getNthPrime(n);
    
    int super_prime = getNthPrime(prime_index);

    std::cout << super_prime << "\n";

    return 0;
}