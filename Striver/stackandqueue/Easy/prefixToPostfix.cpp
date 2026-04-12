// Approach : I have noticed one patter in the code it is similiar to the first
// code which i have done, in which we get a char then simply append it but for
// operator we store it and keep checking for the more small operator, even if
// we get the same presedence one we start poping out, opposite appraoch of the
// first queston, lets try and see am i correct or not

// I was totally wrong, the approach is totally different from this current
// approach let me fix that now, from striver code and sheet

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
string prefixToPostfix(string &s) {
  string result;
  // stack<char> st;
  // this is wrong way of doing the question
  // although it is giving correct result for some cases

  // for (char c : s) {
  //   if (isalnum(c)) {
  //     // append it directly
  //     result += c;
  //   } else {
  //     while (!st.empty() && pres(c) >= pres(st.top())) {
  //       // do the opposite look for smaller ones
  //       // if small add else start poping small ones
  //       result += st.top();
  //       st.pop();
  //     }
  //     // in end just push the new one in
  //     st.push(c);
  //   }
  // }
  // // check if stack is still empty or not
  // while (!st.empty()) {
  //   result += st.top();
  //   st.pop();
  // }
  // return result;
  stack<string> st;
  for (int i = s.length() - 1; i >= 0; i--) {
    char c = s[i];
    if (isalnum(c)) {
      st.push(string(1, c));
    } else {
      // pop last two elements and make them into postfix exprsn
      string s1 = st.top();
      st.pop();
      string s2 = st.top();
      st.pop();
      // store them in postifix expression
      st.push(s1 + s2 + c);
    }
  }
  return st.top();
}
int main() {
  string str = "*+ab-cd";
  cout << prefixToPostfix(str);
  return 0;
}