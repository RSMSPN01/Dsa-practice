// Approach : There is nothing different then a regular approach of the bs just this time we have 
// to keep track of both the low and high at the same time and check on the bases of that
#include <iostream>
#include <vector>
using namespace std;
vector<int> getFloorAndCeil(vector<int> nums, int x) {
    int n = nums.size() - 1;
    int low = 0, high = n, mid = 0;
    int ceil = -1;
    int floor = -1;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (nums[mid] == x) {
            return { x,x };
        } else if (x < nums[mid]) {
            ceil = nums[mid];
            high = mid - 1;
        } else {
            floor = nums[mid];
            low = mid + 1;
        }
    }
    // If any of the values are not present then it is already been handled above 
    // so we don't have to handle that explicitly here again.
    return { floor,ceil };
}
int main() {
    vector<int>nums = { 3, 4, 4, 7, 8, 10 };
    int x = 11;
    vector<int> v = getFloorAndCeil(nums, x);
    for (auto&& i : v)
    {
        cout << i << " ";
    }

    return 0;
}