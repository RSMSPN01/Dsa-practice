#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    // Approach : I can run from back side of the array and keep the track of the
    //  previous most greatest element and then continously compare it with the current 
    //  element if it becomes greater then the previous great element then simply 
    //  store that that is the leader
    vector<int> leaders(vector<int>& nums) {
        int currentMax = INT_MIN;
        vector <int>result;
        for (int i = nums.size() - 1;i >= 0;i--) {
            // compare with the current max element
            if (nums[i] > currentMax) {
                currentMax = nums[i]; // update the most current element
                result.push_back(nums[i]); // Save it in the vector
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

