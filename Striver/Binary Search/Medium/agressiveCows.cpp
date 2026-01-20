// Approach : Brute force : So this is the pattern of finding min of max we need to find 
// the minimum distance b/w the cows that should be maximum 
// we can use linear approach and check from zero for each possible answer

// Better Approach : using bs, it is similar to the previous questions in this we are also 
// doing the same thing, just the valid function has a different use case now.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool possibleDistance(int dist, vector<int>& nums, int k) {
    // using two pointer appraoch to find the valid distance.
    int cowCounts = 1;
    int i = 0, j = 1, n = nums.size();
    while (i < n && j < n) {
        if (nums[j] - nums[i] >= dist) {
            cowCounts++;
            i = j;
        }
        j++;
    }
    if (cowCounts >= k) {
        return true;
    }
    return false;
}
int aggressiveCows(vector<int>& nums, int k) {
    // sort it first so that we can apply bs on this 
    sort(nums.begin(), nums.end());
    int low = 1, high = nums[nums.size() - 1] - nums[0], mid = 0;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (possibleDistance(mid, nums, k)) {
            // search for the max 
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    // in the end high will we at the maximum number 
    return high;
}
int main() {
    int k = 3;
    vector<int> nums = { 10, 1, 2, 7, 5 };
    cout << aggressiveCows(nums, k);
    return 0;
}