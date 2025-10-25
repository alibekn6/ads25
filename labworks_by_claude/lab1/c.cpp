#include <iostream>
#include <stack>
#include <string>
using namespace std;

string processString(const string& s) {
    stack<char> st;

    for (char c : s) {
        if (c == '#') {
            if (!st.empty()) {
                st.pop();
            }
        } else {
            st.push(c);
        }
    }

    string result = "";
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }

    return result;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    string result1 = processString(s1);
    string result2 = processString(s2);

    if (result1 == result2) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
