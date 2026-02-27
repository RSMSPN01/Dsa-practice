// Approach : There could be two approaches that can be used in this

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// First is pure recursion based
// void helper(vector<int> &nums, vector<int> &result, int sum, int i) {
//     if (i == nums.size()) {
//         result.push_back(sum);
//         return;
//     }
//     // here it is included
//     helper(nums, result, sum + nums[i], i + 1);
//     // here it is excluded
//     helper(nums, result, sum, i + 1);
// }

// Second is loop based
void helper(vector<int> &nums, vector<int> &result, int sum, int ind) {
  for (int i = ind; i < nums.size(); i++) {
    result.push_back(sum + nums[i]);
    helper(nums, result, sum + nums[i], i + 1);
  }
}
vector<int> subsetSums(vector<int> &nums) {
  vector<int> result;
  helper(nums, result, 0, 0);
  sort(result.begin(), result.end());
  return result;
}

int main() {
  vector<int> nums = {5, 2, 1};
  vector<int> x = subsetSums(nums);
  for (auto &&i : x) {
    cout << i << " ";
  }

  return 0;
}