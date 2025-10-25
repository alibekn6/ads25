#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    stack<char> st;

    for (size_t i = 0; i < s.length(); i++) {
        char c = s[i];

        if (!st.empty() && st.top() == c) {
            st.pop();
        } else {
            st.push(c);
        }
    }

    if (st.empty()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
