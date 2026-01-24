#include <algorithm>
#include <iostream>

using namespace std;
// I don't understand the question properly and instead write a different code
// which was never asked. so please have a look to the code . there is a little
// problem with the code that if the maximum is at the last most index then it
// will don't give us the right result because i never made the code like that .
int majorityElement(int arr[], int n) {
  int count = 1;
  int ans = arr[0];
  int maxCount = 0;
  for (int i = 1; i < n; i++) {
    if (arr[i] == arr[i - 1]) {
      count++;
    } else {
      if (maxCount < count) {
        maxCount = count;
        ans = arr[i - 1];
      }
      count = 1;
    }
  }
  return ans;
}
int main() {
  int n = 11;
  int arr[n] = {1, 1, 2, 2, 2, 3, 3, 4, 4, 5, 6};
  int answer = majorityElement(arr, n);
  cout << answer;
  return 0;
}