// Approach : I am not be able to think of any approach right now to solve the
// problem although i notcie something in the question, if it is operator then
// store it else just print it How to insert multiplication is the thing which i
// can't understand

// lets seek some help and then try it again

// i didn't look the question correctly and miss out that multiplication sign is
// already given to us i have to implement that only

// Lets try to implement now what i have just learned
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
string prefixToInfinix(string &str) {
  stack<string> s; // take of type string bcs we need to also store the exprsn
  for (int i = str.length() - 1; i >= 0; i--) { // start from the back
    if (isalnum(str[i])) { // fun to check if value is albhabet or numeric value
      s.push(string(1, str[i])); // convert char into string before pushing
    } else {
      // we need to pop out last two values and perform operation
      string s1 = s.top();
      s.pop();
      string s2 = s.top();
      s.pop();
      // store them back again with proper operator symbol
      // and also add brackets in the front and end
      s.push("(" + s1 + str[i] + s2 + ")");
      // we have to keep pushing it back
    }
  }
  // in the the end the answer will be stored at the top by itself
  // dry run if you still don't understand this approach
  return s.top();
}
int main() {
  string s = "*+ab-cd";
  cout << prefixToInfinix(s);
  return 0;
}