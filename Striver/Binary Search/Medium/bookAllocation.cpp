// Approach : Brute force : So we will use a for loop which will start from the maximum 
// no. till the total sum of the pages and we will check for each one and if we find
// the first possible then that is going to be the answer bcs we need minimum

// Better Approach : Using bs, we have a range and we know that the answer lies in a 
// particular range, so we will chech that, we will use the same valid function of 
// the brute force appraoch.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool possiblePages(int pages, vector<int>& nums, int m) {
    int totalStudent = 0, totalPages = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (totalPages + nums[i] <= pages) {
            totalPages += nums[i];
        } else {
            // reset the total no of students
            totalStudent++;
            totalPages = nums[i];
        }
        // we can even early stop here too by checking 
        // if total student exceeds the no by m or not
    }
    if (totalPages > 0) {
        totalStudent++;
    }
    if (totalStudent <= m) {
        return true;
    }
    return false;

}
int findPages(vector<int>& nums, int m) {
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    int low = *max_element(nums.begin(), nums.end()), high = sum, mid = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (possiblePages(mid, nums, m)) {
            // if possible reduce it bcs we need minimum
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}
int main() {
    vector<int> nums = { 25, 46, 28, 49, 24 };
    int m = 4;
    cout << findPages(nums, m);
    return 0;
}