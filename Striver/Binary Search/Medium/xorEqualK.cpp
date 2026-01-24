// Time Complexity = O(n^2) and Space Complexity = O(1)
// Brute force : So i will run two for loops which will count the xor at all the
// instances at any point if it will be equal to k then we are going to update
// the count and in the end just return the count

// Time Complexity = O(n) and Space Complexity = O(n)
// Better Approach : I think  there must be going to be some trick behind this
// in which eithe we have to do something with the bits or some sort of
// observation which i am mising right now. but i am not be able to think of any
// better solution now

// There is no trick but i somewhat have the idea for this problem, this works
// just as subarray sum just formula is changed nothing else same way to look in
// the array i was right just need a little bit more focus on this.

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
int subarraysWithXorK(vector<int> &nums, int k) {
  // start from here.
}
int main() {
  vector<int> nums = {4, 2, 2, 6, 4};
  cout << subarraysWithXorK(nums, 6);
  return 0;
}
