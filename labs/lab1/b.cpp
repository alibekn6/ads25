#include <iostream>

const int MAX_SIZE = 200005;
int custom_stack[MAX_SIZE];
int stack_top_idx = -1;

void push(int value) {
    stack_top_idx++;
    custom_stack[stack_top_idx] = value;
}

void pop() {
    if (stack_top_idx > -1) {
        stack_top_idx--;
    }
}

int top() {
    return custom_stack[stack_top_idx];
}

bool is_empty() {
    return stack_top_idx == -1;
}

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int current_age;
        std::cin >> current_age;

        while (!is_empty() && top() > current_age) {
            pop();
        }

        if (is_empty()) {
            std::cout << -1;
        } else {
            std::cout << top();
        }

        if (i < n - 1) {
            std::cout << " ";
        }

        push(current_age);
    }

    std::cout << "\n";

    return 0;
}