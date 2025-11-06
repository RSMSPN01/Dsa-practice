#include <iostream>
#include <algorithm>
using namespace std;
int minDifference(int arr[], int n, int m) {
    sort(arr, arr + n);
    int minDiff = arr[n - 1];
    int i = 0, j = m - 1;
    while (j < n)
    {
        int diff = arr[j] - arr[i];
        minDiff = min(minDiff, diff);
        i++, j++;
    }
    return minDiff;
}
int main() {
    int n = 8, m = 5;// no of children to distribute chocolate in .
    int arr[n] = { 3,4,1,9,56,7,9,12 };
    cout << minDifference(arr, n, m);
    return 0;
}