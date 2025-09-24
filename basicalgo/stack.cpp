#include <iostream>
#include <stack>
using namespace std;

int main() {
  stack<int> st;

  st.push(14);
  st.push(11);
  st.push(39);


  cout << st.top();
  st.pop();
  cout <<  st.top();


  // 14 11 39
  // top -> 39
  // pop -> to delete 39
  // now top is 11

  // 39 11 14  
  //
  // top = is the last element
  //
  return 0;
}
