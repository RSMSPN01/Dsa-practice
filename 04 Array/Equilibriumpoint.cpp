#include <iostream>
using namespace std;
int equilibriumPoint(int arr[], int n) {
  // return the index by 1 base indexing.
  int totalSum = 0;
  for (int i = 0; i < n; i++) {
    totalSum += arr[i];
  }
  int leftSum = 0;

  for (int i = 0; i < n; i++) {
    int rightSum = totalSum - leftSum - arr[i];
    if (rightSum == leftSum) {
      return i + 1;
    }
    leftSum += arr[i];
  }
  return -1;
}
int main() {
  int n = 5;
  int arr[n] = {1, 3, 5, 2, 2};
  cout << equilibriumPoint(arr, n);
  return 0;
}