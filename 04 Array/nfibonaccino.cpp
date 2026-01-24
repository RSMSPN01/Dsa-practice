#include <iostream>
#include <vector>
using namespace std;
void printNfibonacci(int n, int m) {
  vector<int> v(m, 0);
  v[n - 1] = 1; // v=[0,0,1]
  int windowSum = 1;

  for (int i = n; i < m; i++) {
    v[i] = windowSum;
    windowSum += v[i] - v[i - n];
  }

  for (auto &&i : v) {
    cout << i << " ";
  }
}
int main() {
  int n = 3;
  int m = 8;
  printNfibonacci(n, m);
  return 0;
}