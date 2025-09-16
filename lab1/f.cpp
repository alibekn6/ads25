#include <iostream>

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    
    if (num == 2) {
        return true;
    }

    if (num % 2 == 0) {
        return false;
    }

    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}


int main() {

    int n;
    std::cin >> n;
    int prime_count = 0;
    int current_num = 1;


    while (prime_count < n) {
        current_num++;
        if (isPrime(current_num)) {
            prime_count++;
        }
    }

    std::cout << current_num << "\n";

    return 0;
}