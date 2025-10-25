#include <iostream>

const int QUEUE_CAPACITY = 11;

struct CustomQueue {
    int arr[QUEUE_CAPACITY];
    int head; 
    int tail;  
    int count;

    void init() {
        head = 0;
        tail = 0;
        count = 0;
    }

    bool is_empty() {
        return count == 0;
    }

    void enqueue(int value) {
        arr[tail] = value;
        tail = (tail + 1) % QUEUE_CAPACITY;
        count++;
    }

    int dequeue() {
        int value = arr[head];
        head = (head + 1) % QUEUE_CAPACITY;
        count--;
        return value;
    }
};


int main() {


    CustomQueue boris_deck, nursik_deck;
    boris_deck.init();
    nursik_deck.init();

    for (int i = 0; i < 5; ++i) {
        int card;
        std::cin >> card;
        boris_deck.enqueue(card);
    }

    for (int i = 0; i < 5; ++i) {
        int card;
        std::cin >> card;
        nursik_deck.enqueue(card);
    }

    int moves = 0;
    const int max_moves = 1000000;

    while (moves < max_moves) {

        if (boris_deck.is_empty()) {
            std::cout << "Nursik " << moves << "\n";
            return 0;
        }
        if (nursik_deck.is_empty()) {
            std::cout << "Boris " << moves << "\n";
            return 0;
        }

        int boris_card = boris_deck.dequeue();
        int nursik_card = nursik_deck.dequeue();

        bool boris_wins_turn;
        if (boris_card == 0 && nursik_card == 9) {
            boris_wins_turn = true;
        } else if (nursik_card == 0 && boris_card == 9) {
            boris_wins_turn = false;
        } else if (boris_card > nursik_card) {
            boris_wins_turn = true;
        } else {
            boris_wins_turn = false;
        }

        if (boris_wins_turn) {
            boris_deck.enqueue(boris_card);
            boris_deck.enqueue(nursik_card);
        } else {
            nursik_deck.enqueue(boris_card);
            nursik_deck.enqueue(nursik_card);
        }

        moves++;
    }

    std::cout << "blin nichya\n";

    return 0;
}