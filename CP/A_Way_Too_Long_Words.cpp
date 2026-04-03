#include <bits/stdc++.h>
#include <iostream>

using namespace std;
string formatString(string &s) {
  int n = s.length();
  if (n > 10) {
    string temp;
    temp += s[0];
    temp += to_string(n - 2);
    temp += s[n - 1];
    return temp;
  }
  return s;
}
int main() {
  int n;
  cin >> n;
  while (n > 0) {
    string temp;
    cin >> temp;
    cout << formatString(temp) << endl;
    n--;
  }
  return 0;
}