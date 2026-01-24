#include <iostream>
using namespace std;
void inPlaceFrequency(int *arr, int n) {
  int i = 0;
  while (i < n) {    // the last element is zero then the this code works
    if (arr[i] <= 0) // please handle the edge case seprately if the last
                     // element becomes zero
    {
      i++;
    } else {
      if (arr[arr[i] - 1] < 0) {
        arr[arr[i] - 1] = arr[arr[i] - 1] - 1;
        arr[i] = 0;
        i++;
      } else {
        int index = arr[i] - 1;
        arr[i] = arr[arr[i] - 1];
        arr[index] = -1;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (arr[i] < 0) {
      arr[i] = -arr[i];
    } else {
      arr[i] = 0;
    }
  }
}
int main() {
  int n = 7;
  int arr[n] = {2, 0, 4, 5, 7, 1, 2};

  inPlaceFrequency(arr, n);
  for (auto &&i : arr) {
    cout << i << " ";
  }
  cout << endl;
  for (int i = 0; i < n; i++) {
    cout << i + 1 << " ";
  }

  return 0;
}