#include <iostream>
#include <vector>
using namespace std;
#include <utility>
#include <unordered_set>
#include <unordered_map>

bool solve() {
  vector<int> nums = {1,2,1,4,5,6,4,6,7};
  unordered_set<int> seen;

  for (auto num : nums) {
    if (seen.count(num)) return true;
    seen.insert(num);
  }

  return false;
}

int main() {
  cout << solve();

  return 0;
}

