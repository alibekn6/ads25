

#include <iostream>
#include <stack>
using namespace std;

int main() {

    string s;
    cin >> s;

    stack<char> st;

    // sbaabsss

    for (size_t i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (!st.empty() && st.top() == c) {
            st.pop();
        } else {
            st.push(c);
        }
    }

    if (st.empty()) {
        cout << "YES";
    } else {
        cout << "NO";
    }


    return 0;
}