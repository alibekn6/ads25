#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    deque<int> dq;
    string command;

    while (cin >> command) {
        if (command == "!") {
            break;
        } else if (command == "+") {
            int num;
            cin >> num;
            dq.push_front(num);
        } else if (command == "-") {
            int num;
            cin >> num;
            dq.push_back(num);
        } else if (command == "*") {
            if (dq.empty()) {
                cout << "error\n";
            } else if (dq.size() == 1) {
                cout << dq.front() + dq.front() << "\n";
                dq.clear();
            } else {
                cout << dq.front() + dq.back() << "\n";
                dq.pop_front();
                dq.pop_back();
            }
        }
    }

    return 0;
}
