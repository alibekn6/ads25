#include <deque>
#include <queue>
#include <iostream>
using namespace std;


int main () {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        deque<int> dq;
        for (int i = n; i >= 1; i--) {
            dq.push_front(i);
            for (int j = 0; j < i; j++) {
                int card = dq.back();
                dq.pop_back();
                dq.push_front(card);
            }
        }

        for (int i = 0; i < n; i++) {
            cout << dq[i];
        }




    }

    return 0;
}

// int main () {

//     deque<int> numbers;
//     queue<int> nums;
//     numbers.push_back(1);
//     numbers.push_back(2);
//     numbers.push_back(3);
//     numbers.push_back(4);
//     numbers.push_back(5);
//     // numbers.push_front(99);


//     cout << numbers.front();


//     // while (!numbers.empty()) {
//     //     cout << numbers.back() << " ";
//     //     numbers.pop_back();
//     // }


//     nums.push(3);
//     nums.push(5);
//     nums.push(11);
//     nums.push(46);
//     nums.push(91);


//     // cout << nums.back(); // back 91
//     // cout << nums.front(); // front 3
//     // while (!nums.empty()) {
//     //     cout << nums.front() << " ";
//     //     nums.pop();
//     // }

//     // 5 4 3 2 1 99


//     return 0;
// }

// int main () {
    
//     int t;
//     cin >> t;

//     while (t--) {
//         int n;
//         cin >> n;
//         deque<int> dq;
//         // 4
//         for (int i = n; i >= 1; i--) {
//             dq.push_front(i);
//             // moving fron to back
//             for (int j = 0; j < i; j++) {
//                 int card = dq.back();
//                 dq.pop_back();
//                 dq.push_front(card);
//             }
//         }

//         for (int i = 0; i < n; i++) {
//             cout << dq[i];
//             if (i < n-1) cout << " ";
//         }

//         cout << endl;
//     }

//     return 0;
// }


