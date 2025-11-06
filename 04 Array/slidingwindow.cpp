#include <iostream>
#include <climits>
using namespace std;
int slidingWindow(int arr[], int n, int k) {
    int currSum = 0;
    int maxSum = INT_MIN;
    for (int i = 0; i < k; i++)
    {
        currSum += arr[i];
    }
    maxSum = currSum;
    for (int i = k; i < n; i++)
    {
        currSum += arr[i] - arr[i - k];
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}
int main() {
    int n = 6;
    int arr[n] = { 1,2,3,-4,5,6 };
    int k = 3;
    cout << slidingWindow(arr, n, k);
    return 0;
}