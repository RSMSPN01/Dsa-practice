#include <iostream>
using namespace std;
// this same approach is used in the movezerotoend as well.
int removeDuplicate(int arr[], int n) {
  int res = 1;
  for (int i = 1; i < n; i++) {
    if (arr[i] != arr[res - 1]) {
      arr[res] = arr[i];
      res++;
    }
  }
  return res;
}
int main() {
  int n = 6;
  int arr[n] = {10, 10, 20, 20, 20, 30};
  int result = removeDuplicate(arr, n);
  for (int i = 0; i < result; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}