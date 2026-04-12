// Approach : Now i am able to understand a little bit more about the pattern
// almost every one of these follow similiar kind of pattern just a littlle
// tweek here and there, just convert this into infix expression thats it

#include <bits/stdc++.h>
#include <iostream>

using namespace std;
string postfixToInfinix(string &s) {
  stack<string> st;
  for (char c : s) {
    if (isalnum(c)) {
      st.push(string(1, c));
    } else {
      // just convert it
      string s1 = st.top();
      st.pop();
      string s2 = st.top();
      st.pop();
      // infix expression
      st.push("(" + s2 + c + s1 + ")");
    }
  }
  return st.top();
}
int main() {
  string str = "abc*+";
  cout << postfixToInfinix(str);
  return 0;
}