#include <bits/stdc++.h>
#include <iostream>

using namespace std;





string processString(string s) {
    stack<char> st;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '#') {
            if (!st.empty()) {
                st.pop();
            }
        } else {
            st.push(s[i]);
        }
    }

    string result = "";
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;

}

int main() {
    string a, b;
    cin >> a >> b;

    if (processString(a) == processString(b)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;

}