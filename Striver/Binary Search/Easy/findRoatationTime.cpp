#include <iostream>
#include <vector>
using namespace std;
// Approach : I think this is the follow up question of the find th minumum element in rotated 
// sorted array because the array is rotated as many times as the index of the minimum element 
// in the array

int findKRotation(vector<int>& nums) {
    // find the minimum in the array using bs
    int n = nums.size();
    int start = 0, end = n - 1, mid = 0;
    while (start < end)
    {
        mid = start + (end - start) / 2;
        if (nums[mid] > nums[end])
        {
            // it means array is rotated search in the right side 
            start = mid + 1;
        } else {
            end = mid;
            // don't make it to mid -1 bcs in that way we can miss the min element
        }
    }
    return start;
}

int main() {
    vector<int> v = { 4, 5, 6, 7, 0, 1, 2, 3 };
    cout << findKRotation(v);
    return 0;
}