#include <bits/stdc++.h>
#include <iostream>

using namespace std;
bool canDivide(int n) {
  if (n <= 2) {
    return false;
  }
  if (n % 2 == 0) {
    return true;
  }
  return false;
}
int main() {
  // your code goes here
  int n;
  cin >> n;
  if (canDivide(n)) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}