// just print the nth prime number

#include <iostream>
using namespace std;
#include <bits/stdc++.h>


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

int main() {

    int n;
    cin >> n;
    int prime_count = 0;
    int cur_num = 1;


    while (prime_count < n) {
        cur_num++;
        if (isPrime(cur_num)) {
            prime_count++;
        }
    }

    cout << cur_num;

    return 0;
}