#include <iostream>
#include <deque>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        deque<int> deck;

        for (int i = n; i >= 1; i--) {
            deck.push_front(i);

            for (int j = 0; j < i; j++) {
                int last = deck.back();
                deck.pop_back();
                deck.push_front(last);
            }
        }

        for (int i = 0; i < n; i++) {
            cout << deck[i];
            if (i < n - 1) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}
