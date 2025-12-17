#include <iostream>
#include <vector>
using namespace std;
// LowerBound basically means either we find out the no x directly or find the just next greater
// element then the x, if no such no. is found then return the size of the array itself
int lowerBound(vector<int>& nums, int x) {
    int low = 0;
    int high = nums.size() - 1;
    int mid = 0;
    int lastIndex = -1;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (nums[mid] >= x) {
            lastIndex = mid;     // possible lower bound
            high = mid - 1;     // go left
        } else {
            low = mid + 1;     // go right
        }
    }
    return ((lastIndex >= 0) ? lastIndex : nums.size());
}
int main() {
    vector <int> v = { 3,5,8,15,19 };
    int x = 9;
    cout << lowerBound(v, x);
    return 0;
}