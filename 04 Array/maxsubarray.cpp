#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;
// kadanes algorithm
int maxSubArray(int arr[], int n) {
  int maxSum = INT_MIN;
  int currSum = 0;
  for (int i = 0; i < n; i++) {
    currSum += arr[i];
    maxSum = max(maxSum, currSum);
    if (currSum < 0) {
      currSum = 0;
    }
  }
  return maxSum;
}

int main() {
  int n = 9;
  int arr[n] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int result = maxSubArray(arr, n);
  cout << result;
  return 0;
}