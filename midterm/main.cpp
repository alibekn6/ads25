#include <iostream>
    #include <bits/stdc++.h>
using namespace std;


// b solution
int main () {
    int n;
    cin >> n;
    vector<int> ages(n);

    for (int i = 0; i < n; i++) {
        cin >> ages[i];
    }

    vector<int> result;
    vector<int> stack;

    for (int i = 0; i < n; i++) {
        int current = ages[i];
        int found = -1;

        for (int j = stack.size() - 1; j >= 0; j--) {

        }
    }


    return 0;
}

// stack