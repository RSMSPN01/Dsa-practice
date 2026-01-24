#include <algorithm>
#include <iostream>

using namespace std;
int totalWater(int water[], int n) {
  // we are using two pointer approach here rather then just brute force
  // approach.
  int lp = 0;
  int rp = n - 1;
  int area = 0;
  while (lp < rp) {
    int width = rp - lp;
    int height = min(water[lp], water[rp]);
    area = max(area, (height * width));
    (water[lp] < water[rp] ? lp++ : rp--);
  }
  return area;
}
int main() {
  int n = 7;
  int arr[n] = {5, 2, 0, 3, 5, 0, 3};
  int answer = totalWater(arr, n);
  cout << answer;
  return 0;
}