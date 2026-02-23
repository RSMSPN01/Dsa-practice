// this is the most basics of the pattern printing if you can do this, congrats!
// you can move ahead then
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> powerSet(vector<int> &nums, vector<int> &temp, int i,
                             vector<vector<int>> &result) {
  if (i == nums.size()) {
    // base case
    result.push_back(temp);
  }
  // include it first
  temp.push_back(nums[i]);
  // now call that again
  powerSet(nums, temp, i + 1, result);
  // not remove it
  temp.pop_back();
  // agian call that
  powerSet(nums, temp, i + 1, result);
  // in the end return it
  return result;
}

int main() {
  vector<int> nums = {1, 2, 3};
  vector<int> quack;
  vector<vector<int>> temp;
  vector<vector<int>> x = powerSet(nums, quack, 0, temp);
  for (int i = 0; i < x.size(); i++) {
    for (int j = 0; j < x[i].size(); j++) {
      cout << x[i][j] << " ";
    }
  }
  return 0;
}