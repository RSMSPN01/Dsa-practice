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

#include <bits/stdc++.h>
#include <iostream>

using namespace std;
int canPlace(long double dist, vector<int> &nums) {
  // this will checks how many gas stations can pe placed in between
  int totalNoOfStations = 0;
  for (int i = 1; i < nums.size(); i++) {
    // This ceil function is costly to call each time you can simply convert
    // this into mathematical terms to reduce the T.C
    totalNoOfStations += ceil((nums[i] - nums[i - 1]) / dist) - 1;
  }
  return totalNoOfStations;
}
long double minimiseMaxDistance(vector<int> &nums, int k) {
  int n = nums.size();
  long double low = 0, high = 0;

  // Determine max initial distance between stations
  for (int i = 0; i < n - 1; i++) {
    high = max(high, (long double)(nums[i + 1] - nums[i]));
  }

  long double diff = 1e-6;

  // Binary search to find minimum possible maximum distance
  while (high - low > diff) {
    long double mid = (low + high) / 2.0;
    int cnt = canPlace(mid, nums);
    if (cnt > k)
      low = mid;
    else
      high = mid;
  }

  return high;
}
int main() {
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int k = 10;
  cout << minimiseMaxDistance(nums, k) << endl;
  return 0;
}