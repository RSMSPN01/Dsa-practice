// Approach : Brute force : So we will do a linear search on that where, the
// loop starts from the min distance between two points divided by 2 bcs that
// could be the most min possible answer and it will goes till arr[max] -
// arr[min]. // don't even be able to think for the brute force i don't think
// so this will even work i have just wrote it down but this will not work.

// Better Approach : We know we have a range to find the answer so we can apply
// that its a same question of pattern min of max just data types has changed
// and a little bit tweak into the valid function lets see am i thinking in the
// right direction.

// There is also a little wierd thing in question, the approach i am going to
// write is that we can only put one gas station in between the two consecutive
// stations

// After thinking on it i find out i am wrong, if we will start putting
// one or even more gas station in between then, we will not be able to find the
// max as our output bcs the value is just going to get down and even down,
// instead putting more in between directly put them in the end please think
// about why i am saying this you will get to know that

// I am trying to solve this question for so much long time still not be able to
// think for the valid function how i am going to write that lets see what can i
// learn from video and try to implement that here.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
bool canPlace(int mid, vector<int> &nums, int k) {
  // This approach which i have write here, there is no single way this could
  // work it will always return the ans as false idk why i have even written
  // this

  // int count = 0, lastCount = 0;
  // for (int i = 1; i < nums.size(); i++) {
  //   if (nums[i] - lastCount >= mid) {
  //     count++;
  //     lastCount = i;
  //   }
  //   // can use early stopping but hardly makes the code faster
  // }
  // if (count >= k) {
  //   return true;
  // }
  // return false;
}
long double minimiseMaxDistance(vector<int> &nums, int k) {
  int n = nums.size();
  // handle edge cases

  int minAdjacentDistance = 1;
  // for (int i = 1; i < nums.size(); i++) {
  //   if (nums[i] - nums[i - 1] < minAdjacentDistance) {
  //     minAdjacentDistance = nums[i] - nums[i - 1];
  //     // this is going to be our starting point
  //   }
  // }
  long double low = minAdjacentDistance, high = nums[n - 1] - nums[0];
  long double mid = 0.0;
  while (low <= high) {
    mid = low + (high - low) / 2.0;
    if (canPlace(mid, nums, k)) {
      // search for the max
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return high;
}
int main() {
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int k = 10;
  cout << minimiseMaxDistance(nums, k);
  return 0;
}