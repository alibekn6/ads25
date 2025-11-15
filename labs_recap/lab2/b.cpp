#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Jonathan the Poet
int main() {
    int n, k;
    cin >> n >> k;

    vector<string> words(n);


    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    // for (int i = 0; i < n; i++) {
    //     if (i > 0) cout << " ";
    //     cout << words[(i + k) % n];
    // }


    rotate(words.begin(), words.begin() + k, words.end());

    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << words[i];
    }

    cout << endl;

    return 0;
}






#include <iostream>

#include <vector>
#include <queue>
#include <unordered_map>

void firstNonRepeating() {
    std::unordered_map<char, int> countMap;
    std::queue<char> charsQueue;\n    ˜int N;\n    std::cin >> N;\n    char ch;\n    for (int i = 0; i < N; i++) {\n        std::cin >> ch;\n        countMap[ch]++;\n        charsQueue.push(ch);\n        while (!charsQueue.empty()) {\n            if (countMap[charsQueue.front()] > 1) {\n                charsQueue.pop();\n            } else {\n                std::cout << charsQueue.front() << \" \";\n                break;\n            }\n        }\n        if (charsQueue.empty()) {\n            std::cout << -1 << \" \";\n        }\n    }\n    std::cout << std::endl;\n}\n\nint main() {\n    int T;\n    std::cin >> T;\n    while (T--) {\n        firstNonRepeating();\n    }\n    return 0;\n}\n

