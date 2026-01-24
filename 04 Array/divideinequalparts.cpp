#include <iostream>
using namespace std;
bool isdividePossible(int arr[], int n) {
  // check if array can be cut into three equal sum or not .
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  if (sum % 3 == 0) {
    int value = sum / 3; // in this case stores 6
    int count = 0;
    int currSum = 0;
    for (int i = 0; i < n; i++) {
      currSum += arr[i];
      if (currSum == value) {
        count++;
        currSum = 0;
      }
    }
    if (count == 3) {
      return true;
    } else {
      return false;
    }

  } else {
    return false;
  }
}
int main() {
  int n = 7;
  int arr[n] = {1, 1, 1, 1, 2, 2, 4};
  cout << isdividePossible(arr, n);
  return 0;
}