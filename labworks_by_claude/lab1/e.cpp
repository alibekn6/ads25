#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> boris, nursik;

    for (int i = 0; i < 5; i++) {
        int card;
        cin >> card;
        boris.push(card);
    }

    for (int i = 0; i < 5; i++) {
        int card;
        cin >> card;
        nursik.push(card);
    }

    int moves = 0;
    const int MAX_MOVES = 1000000;

    while (!boris.empty() && !nursik.empty() && moves < MAX_MOVES) {
        int b = boris.front();
        int n = nursik.front();
        boris.pop();
        nursik.pop();

        if ((b > n && !(b == 9 && n == 0)) || (b == 0 && n == 9)) {
            boris.push(b);
            boris.push(n);
        } else {
            nursik.push(b);
            nursik.push(n);
        }

        moves++;
    }

    if (moves == MAX_MOVES) {
        cout << "blin nichya\n";
    } else if (boris.empty()) {
        cout << "Nursik " << moves << "\n";
    } else {
        cout << "Boris " << moves << "\n";
    }

    return 0;
}
