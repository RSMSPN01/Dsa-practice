// Approach : Brute force : So we will do a linear search on that where, the loop starts
// from the min distance between two points divided by 2 bcs that could be the most min
// possible answer and it will goes till arr[max] - arr[min].

// Better Approach : We know we have a range to find the answer so we can apply that
// its a same question of pattern min of max just data types has changed and a little
// bit tweak into the valid function
// lets see am i thinking in the right direction.

// There is also a little wierd thing in question, the approach i am going to write is
// that we can only put one gas station in between the two consecutive stations
// After thinking on it i find out i am wrong, if we will start putting one or even more
// gas station in between then, we will not be able to find the max as our output bcs
// the value is just going to get down and even down, instead putting more in between
// directly put them in the end
// please think about why i am saying this you will get to know that

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
bool canPlace(int mid, vector<int>& nums, int k) {
    int count = 0, lastCount = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] - lastCount >= mid) {
            count++;
            lastCount = i;
        }
        // can use early stopping but hardly makes the code faster
    }
    if (count >= k) {
        return true;
    }
    return false;
}
long double minimiseMaxDistance(vector<int>& nums, int k) {
    int n = nums.size();
    // handle edge cases

    int minAdjacentDistance = nums[n - 1];
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] - nums[i - 1] < minAdjacentDistance) {
            minAdjacentDistance = nums[i] - nums[i - 1];
            // this is going to be our starting point
        }
    }
    long double low = minAdjacentDistance, high = nums[n - 1] - nums[0], mid = 0.0;
    while (low <= high) {
        mid = low + (high - low) / 2.0;
        if (canPlace(mid, nums, k)) {
            // search for the max
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return high;
}
int main() {
    vector<int> nums = { 1, 5 };
    int k = 1;
    cout << minimiseMaxDistance(nums, k);
    return 0;
}