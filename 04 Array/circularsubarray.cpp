#include <iostream>
#include <climits>
using namespace std;
int maxCircularSubarraySum(int arr[], int n) {
    // step 1 (Stores the maxSum in straight array)
    int currMaxSum = 0;
    int currMinSum = 0;
    int maxSum = INT_MIN; // compare this with cssm for max.
    // step 2: (Cssm ) S= S1+S2 where S is the total sum and S2 in the minimum Sum 
    // So S1= S-S2 to calculate the circular sub array max sum.
    int totalSum = 0; // This is S
    int MinSum = INT_MAX; // This is S2
    for (int i = 0; i < n; i++)
    {
        totalSum += arr[i];
        currMaxSum += arr[i];
        maxSum = max(maxSum, currMaxSum);
        if (currMaxSum < 0)
        {
            currMaxSum = 0;
        }

        currMinSum += arr[i];
        MinSum = min(MinSum, currMinSum);
        if (currMinSum > 0)
        {
            currMinSum = 0;
        }
    }

    // int circularMaxSum = totalSum - MinSum; // this is S1  = S-S2;
    if (maxSum > 0)
    {
        return max(totalSum - MinSum, maxSum);
    } else {
        return maxSum;
    }
}
int main() {
    int n = 6;
    int arr[n] = { 4,-2,6,8,1,-2 };
    cout << maxCircularSubarraySum(arr, n) << endl;
    return 0;
}