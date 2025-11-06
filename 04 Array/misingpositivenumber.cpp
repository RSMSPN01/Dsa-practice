#include <iostream>
using namespace std;
int smallestPositiveMissingNumber(int arr[], int n) {
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= 0)
        {
            arr[i] = n + 1; // handle all the negative and zeros values by making them out of the bound.
        }
    }
    for (int i = 0; i < n; i++)
    {
        int index = abs(arr[i]);
        if (index <= n)
        {
            if (arr[index - 1] < 0) { continue; } // add this line to handle edge cases in the array // [1,1]
            arr[index - 1] = -arr[index - 1];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            return i + 1;
        }
    }
    return n + 1;
}
int main() {
    int n = 2;
    int arr[n] = { 1, 1 };
    cout << smallestPositiveMissingNumber(arr, n);
    return 0;
}