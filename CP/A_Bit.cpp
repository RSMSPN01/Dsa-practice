#include <iostream>
#include <string>
using namespace std;

int main() {
  int n;
  int x = 0;
  cin >> n;
  while (n > 0) {
    string temp;
    cin >> temp;
    // helper function to calcualte value
    if (temp[1] == '+') {
      x++;
    } else {
      x--;
    }
    n--;
  }
  cout << x;
  return 0;
}