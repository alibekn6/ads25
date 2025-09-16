#include <iostream>

const int DEQUE_CAPACITY = 1001;
int deque_arr[DEQUE_CAPACITY];
int head;          // Index of the first element
int tail;          // Index *after* the last element
int deque_count;   // Number of elements in the deque

void init_deque() {
    head = 0;
    tail = 0;
    deque_count = 0;
}

void add_front(int val) {
    head = (head - 1 + DEQUE_CAPACITY) % DEQUE_CAPACITY;
    deque_arr[head] = val;
    deque_count++;
}

int remove_back() {
    tail = (tail - 1 + DEQUE_CAPACITY) % DEQUE_CAPACITY;
    int val = deque_arr[tail];
    deque_count--;
    return val;
}

void solve() {
    int n;
    std::cin >> n;

    if (n == 0) {
        std::cout << "\n";
        return;
    }

    init_deque();


    for (int i = n; i >= 1; --i) {
        add_front(i);
        for (int j = 0; j < i; ++j) {
            int card_to_move = remove_back();
            add_front(card_to_move);
        }
    }

    int current_idx = head;
    for (int i = 0; i < deque_count; ++i) {
        std::cout << deque_arr[current_idx] << (i == deque_count - 1 ? "" : " ");
        current_idx = (current_idx + 1) % DEQUE_CAPACITY;
    }
    std::cout << "\n";
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}