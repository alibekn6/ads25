#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
  int n;
  cin >> n;
  string votes;
  cin >> votes;

  queue<int> s_queue;
  queue<int> k_queue;

  for (int i = 0; i < n; i++) {
    if (votes[i] == 'S') {
      s_queue.push(i);
    } else {
      k_queue.push(i);
    }
  }

  int last_turn_s = -1;
  int last_turn_k = -1;

  while (!k_queue.empty() && !s_queue.empty()) {
    int s_turn_idx = s_queue.front();
    int k_turn_idx = k_queue.front();

    s_queue.pop();
    k_queue.pop();

    if (s_turn_idx < k_turn_idx) {
      s_queue.push(s_turn_idx + n);
    } else {
      k_queue.push(k_turn_idx + n);
    }
  }

  if (!k_queue.empty()) {
    cout << "KATSURAGI";
  } else {
    cout << "SAKAYANAGI";
  }




  return 0;
}
