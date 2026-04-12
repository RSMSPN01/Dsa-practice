// Approach : so i am thinking to do the same as the last one, i will start from
// the front and change the expression to prefix i don't know will that work or
// not but lets see, i choose to start from the front bcs we have atleast some
// operands to which we can use the operartors

// so i have done it in the right way, good job mate
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

string postfixToPrefix(string &s) {
  stack<string> st;
  for (char c : s) {
    if (isalnum(c)) {
      // push directly
      st.push(string(1, c));
    } else {
      // convert into prefix expression
      string s1 = st.top();
      st.pop();
      string s2 = st.top();
      st.pop();
      st.push(c + s2 + s1);
    }
  }
  return st.top();
}

int main() {
  string str = "xyz*+ab/-";
  cout << postfixToPrefix(str);
  return 0;
}