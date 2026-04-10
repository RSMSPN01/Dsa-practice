// Approach : To be honest i don't find any way to solve the problem neither i
// have any brute force to solve the problem lets seek some help from video and
// then will come back

// So i don't think so there is any logic behind these questions you just have
// to remember these in your mind just by looking at them or doing a little bit
// dry run

// In this what we do is we keep on adding the operands and keep storing the
// operators if the current presendence of the operator is smaller then we will
// keep on poping it out till we don't get a larger presendence, that is it in
// this

#include <bits/stdc++.h>
#include <iostream>

using namespace std;
string infixToPostfix(string &str) {

  // My approach of solving nah dude not working at all only some test cases are
  // getting passed getting help from the video now
  // to store the presedence of
  // the operands unordered_map<char, int> presedence = {{'^', 3}, {'*', 2},
  // {'/', 2}, {'+', 1},
  //                                        {'-', 1}, {'(', 0}, {')', 0}};
  // stack<char> s; // stack to store the operators
  // string result;
  // for (auto &&it : str) {
  //   if (presedence.find(it) != presedence.end()) {
  //     // also check if the top of stack has smaller presedence then only
  //     store if (s.empty() || presedence[s.top()] < presedence[it]) {
  //       s.push(it);
  //     } else {
  //       // presendence is high
  //       while (!s.empty() &&
  //              (s.top() != '(' || presedence[s.top()] > presedence[it])) {
  //         result += s.top();
  //         s.pop();
  //       }
  //       if (!s.empty() && s.top() == '(') {
  //         s.pop();
  //       }
  //       s.push(it);
  //     }
  //   } else {
  //     result += it;
  //   }
  // }
  // while (!s.empty()) {
  //   if (s.top() != ')') {
  //     result += s.top();
  //   }
  //   s.pop();
  // }
  // return result;

  // striver way of writing the code
  // instead of map using if else function
  unordered_map<char, int> presedence = {{'^', 3}, {'*', 2}, {'/', 2}, {'+', 1},
                                         {'-', 1}, {'(', 0}, {')', 0}};
  stack<char> s;
  string result;
  for (char &c : str) {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
        (c >= 0 && c <= 9)) {
      // it means it is operant
      result += c;
    } else if (c == '(') {
      s.push(c);
    } else if (c == ')') {
      while (!s.empty() && s.top() != '(') {
        result += s.top();
        s.pop();
      }
      s.pop();
      // make sure don't add the closing bracker and also remove the opening
      // bracket from the stack this loops handle that
    }
    // don't even write to this in seprate condition this will handle down
    // in the next condtion
    // else if (presedence[c] > s.top()) {
    //   s.push(c);
    // }
    else {
      while (!s.empty() && presedence[c] <= presedence[s.top()]) {
        result += s.top();
        s.pop();
      }
      s.push(c);
    }
  }
  // empty the stack and print all the values out
  while (!s.empty()) {
    result += s.top();
    s.pop();
  }
  return result;
}
int main() {
  string str = "(a+b)*c";
  cout << infixToPostfix(str);
  return 0;
}