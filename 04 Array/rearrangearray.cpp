#include <iostream>
using namespace std;
void rearrangeArray(int arr[], int n) {
  int max = arr[n - 1] + 1;
  int maxIndex = n - 1;
  int minIndex = 0;
  for (int i = 0; i < n; i++) {
    // new value = arr[i]/max;   // divident/divisor
    // old value = arr[i]%max;   // divident%divisor
    // divident = quotient * (divisor) + remainder;
    //            new value              old value;
    //
    if (!(i & 1)) {
      arr[i] = (arr[maxIndex] % max) * max + arr[i];
      maxIndex--;

    } else {
      arr[i] = (arr[minIndex] % max) * max + arr[i];
      minIndex++;
    }
  }
  for (int i = 0; i < n; i++) {
    arr[i] /= max;
  }
}
int main() {
  int n = 6;
  int arr[n] = {1, 2, 3, 4, 5, 6};
  rearrangeArray(arr, n);
  for (auto &&i : arr) {
    cout << i << " ";
  }

  return 0;
}