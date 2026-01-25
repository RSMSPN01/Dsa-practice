// Naive appraoch : i don't know any naive appraoch for this question

// Optimal Appproach : Using extra space (map), logic is this that if we
// maintain a pre sum of all the numbers, then there will we a point when a
// number will repeat itself, why bcs when a subarray has a sum 0 then the
// previous sum will repeat and we have to check if the sum is repeated or not
// this is the whole logic behind this

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
int maxLen(vector<int> &nums) {
  int n = nums.size();
  unordered_map<int, int> preSum;
  int count = 0, curSum = 0;
  for (int i = 0; i < n; i++) {
    // check for the all the zeros condition here
    if (nums[i] == 0) {
      count = i + 1;
    }

    curSum += nums[i];
    // now check if curSum is present or not, if not then add it
    // with its current index
    if (preSum.find(curSum) == preSum.end()) {
      preSum[curSum] = i;
    } else {
      // store the max distance
      count = max(count, (i - preSum[curSum]));
    }
  }
  // it may fail at edge cases when there are all zero elements in that case you
  // just need an extra check here for that the size of the map is one and that
  // one element is zero or not

  // This is the mistake which i was doing here instead of directly checking
  // it on first place i was checking that all the elements are zero or not in
  // this way quite wrong way i must say that

  //   if (preSum.size() == 1) {
  //     auto it = preSum.begin();
  //     if (it->first == 0) {
  //       return count + 1;
  //     }
  //   }
  return count;
}

int main() {
  vector<int> nums = {0, 0, 0, 0};
  cout << maxLen(nums);
  return 0;
}