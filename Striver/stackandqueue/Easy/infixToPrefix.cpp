// Approach : I am not be able to think of any good approach for this one lets
// see the solution and then try again
// I look the editorial and the code seems too big lets watch the video directly

// There are three steps to solve the pattern
// 1. Reverse the string, and handle the brackets
// 2. Convert this into postfix expression, but conditions will strictly to
// > elements not >=
// 3. Again reverse the string and we have the answer
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
int pres(char c) {
  if (c == '^') {
    return 3;
  } else if (c == '/' || c == '*') {
    return 2;
  }
  return 1;
}
string infixToPostfix(string &st) {
  string result;
  stack<char> s;
  for (char c : st) {
    if (isalnum(c)) {
      result += c;
    } else if (c == '(') {
      s.push('(');
    } else if (c == ')') {
      while (!s.empty() && s.top() != '(') {
        result += s.top();
        s.pop();
      }
      s.pop();
    } else {
      // make sure to write the correct condition
      // < not <= in the conventional infix to postfix
      while (!s.empty() && pres(c) < pres(s.top())) {
        result += s.top();
        s.pop();
      }
      s.push(c);
    }
  }
  while (!s.empty()) {
    result += s.top();
    s.pop();
  }
  return result;
}
string infixToPrefix(string &st) {
  // step 1
  reverse(st.begin(), st.end());
  for (int i = 0; i < st.length(); i++) {
    // just swap them
    if (st[i] == ')') {
      st[i] = '(';
    } else if (st[i] == '(') {
      st[i] = ')';
    }
  }
  // step 2
  string temp = infixToPostfix(st);
  // step3
  reverse(temp.begin(), temp.end());
  return temp;
}
int main() {
  string str = "((a-(b/c))*((a/k)-l))";
  cout << infixToPrefix(str);
  return 0;
}