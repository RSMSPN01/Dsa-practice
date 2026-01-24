#include <iostream>
using namespace std;
void flipingBit(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    if (arr[i] != arr[i - 1]) {
      if (arr[i] != arr[0]) {
        cout << "Flip from " << i << " to ";
      } else {
        cout << i - 1 << endl;
      }
    }
  }
  if (arr[n - 1] != arr[0]) {
    cout << n - 1 << endl;
  }
}
int main() {
  int n = 9;
  int arr[n] = {0, 0, 1, 1, 1, 0, 0, 1, 1};
  flipingBit(arr, n);
  return 0;
}