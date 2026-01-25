// Time Complexity = O(n^2) and Space Complexity = O(1)
// Brute force : So i will run two for loops which will count the xor at all the
// instances at any point if it will be equal to k then we are going to update
// the count and in the end just return the count

// Time Complexity = O(n) and Space Complexity = O(n)
// Better Approach : I think  there must be going to be some trick behind this
// in which either we have to do something with the bits or some sort of
// observation which i am mising right now. but i am not be able to think of any
// better solution now

// There is no trick but i somewhat have the idea for this problem, this works
// just as subarray sum just formula is changed nothing else same way to look in
// the array.

// it is kind of similar problem to subArray sum but a little different approach
// so what we have x ^ k = totalXor of array so,what we can do is we can
// calculate the totalXor and we already have k given so we can check that is
// there any x exists or not in the map.

// if you still can't understand go watch the video again.

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
int subarraysWithXorK(vector<int> &nums, int k) {
  unordered_map<int, int> totalXor;
  int count = 0, currXor = 0;
  // push the value 0 so that it is going to help us further
  totalXor[0] = 1;
  for (int i = 0; i < nums.size(); i++) {
    // this is the Current Xor we are calculating right now
    currXor ^= nums[i];
    // now formula is x = totalXor ^ k so check that now
    int x = currXor ^ k;
    if (totalXor.find(x) != totalXor.end()) {
      // if found in map then count the occurences of it
      count += totalXor[x];
    }
    // put the total xor we have calculated till now
    totalXor[currXor]++;
  }
  return count;
}

int main() {
  vector<int> nums = {5, 2, 9};
  cout << subarraysWithXorK(nums, 7);
  return 0;
}
