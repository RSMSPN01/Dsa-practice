#include <iostream>
using namespace std;
bool checkSubarraySum(int arr[], int n, int value) {
    int currSum = 0;
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        if (currSum == value)
        {
            return true;
        } else if (currSum > value)
        {
            while (currSum >= value)
            {
                currSum -= arr[k];
                k++;
            }
            if (currSum == value)
            {
                return true;
            }
        }
    }
    return false;
}
int main() {
    int n = 6;
    int arr[n] = { 1,4,20,3,10,5 };
    int value = 33;
    cout << checkSubarraySum(arr, n, value);
    return 0;
}