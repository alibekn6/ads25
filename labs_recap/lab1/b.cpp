#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    stack<int> st;

    for (int i = 0; i < n; i++) {
        int cur_age;
        cin >> cur_age;

        while (!st.empty() && st.top() >= cur_age) {
            st.pop();
        }

        if (st.empty()) {
            cout << -1;
        } else {
            cout << st.top();
        }

        st.push(cur_age);

        if (i < n - 1) {
            cout << " ";
        }
    }

    

    return 0;
}