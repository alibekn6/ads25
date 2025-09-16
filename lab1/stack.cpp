

#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int top;
    int capacity;
public:
    Stack(int cap) {
        capacity = cap;
        arr = new int[capacity];
        top = -1;
    }
    ~Stack() { delete[] arr; }
    void push(int x) { if (top < capacity - 1) arr[++top] = x; }
    void pop() { if (top >= 0) top--; }
    int peek() { return arr[top]; }
    bool empty() { return top == -1; }
};

int main() {
    int N;
    cin >> N;
    int* a = new int[N + 1];
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    Stack s(N);
    int* ans = new int[N + 1];
    for (int i = 1; i <= N; i++) {
        while (!s.empty() && a[s.peek()] >= a[i]) {
            s.pop();
        }
        if (s.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = a[s.peek()];
        }
        s.push(i);
    }
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    delete[] a;
    delete[] ans;
    return 0;
}


