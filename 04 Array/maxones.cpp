#include <iostream>
#include <algorithm>
using namespace std;
int countConsecutiveOnes(int arr[], int  n) {
    int maxOnes = 0;
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] & arr[i - 1])
        {
            count++;
        } else {
            maxOnes = max(maxOnes, count);
            count = 1;
        }
    }
    if (count > maxOnes)
    {
        return count;
    }

    return maxOnes;
}
int main() {
    int n = 6;
    int arr[n] = { 1,1,0,1,0,1 };
    int result = countConsecutiveOnes(arr, n);
    cout << result;
    return 0;
}