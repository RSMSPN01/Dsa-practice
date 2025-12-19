#include <iostream>
#include <vector>
//Approach : Use direct binary search on this and find the next greater number then this
// and that is it 
using namespace std;

int upperBound(vector<int>& nums, int x) {
    int low = 0;
    int high = nums.size() - 1;
    int mid = 0;
    int index = -1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (nums[mid] <= x)
        {
            low = mid + 1;
        } else {
            index = mid;
            high = mid - 1;
        }
    }
    return (index != -1) ? index : nums.size();
}
int main() {
    vector<int> v = { 3,5,8,15,19 };
    int x = 9;
    cout << upperBound(v, x);
    return 0;
}