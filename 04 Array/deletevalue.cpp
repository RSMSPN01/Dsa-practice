#include <iostream>
using namespace std;

int main() {
  int n = 6;
  int arr[n] = {1, 4, 8, 12, 6, 5};
  int value = 12; // to delete
  for (int i = 0; i < n; i++) {
    if (value == arr[i]) {
      for (int j = i; j < n - 1; j++) {
        arr[j] = arr[j + 1];
      }
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}