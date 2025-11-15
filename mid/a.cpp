#include <iostream>
#include <vector>
using namespace std;

int main () {
    string s;
    cin >> s;

    vector<int> vc;

    for (int i = 0; i < s.size(); i++) {
        if (!vc.empty() && vc.back() == s[i]) {
            vc.pop_back();
        } else {
            vc.push_back(s[i]);
        }
    }



    for (int i = 0; i < vc.size(); i++) {
        cout << char(vc[i]);
    }



    return 0;
}