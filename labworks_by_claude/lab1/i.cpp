#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    int n;
    string students;
    cin >> n >> students;

    queue<int> sakayanagi, katsuragi;

    for (int i = 0; i < n; i++) {
        if (students[i] == 'S') {
            sakayanagi.push(i);
        } else {
            katsuragi.push(i);
        }
    }

    while (!sakayanagi.empty() && !katsuragi.empty()) {
        int s = sakayanagi.front();
        int k = katsuragi.front();

        if (s < k) {
            sakayanagi.pop();
            sakayanagi.push(s + n);
            katsuragi.pop();
        } else {
            katsuragi.pop();
            katsuragi.push(k + n);
            sakayanagi.pop();
        }
    }

    if (sakayanagi.empty()) {
        cout << "KATSURAGI\n";
    } else {
        cout << "SAKAYANAGI\n";
    }

    return 0;
}
