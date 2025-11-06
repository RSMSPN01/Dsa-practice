#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;
// Note :- WE have to find the max in terms of a[j]-a[i] where j is always greater.
int findMax(int arr[], int n) {
    int maxi = arr[n - 1];
    int maxDiff = INT_MIN;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > maxi)
        {
            maxi = arr[i];
        } else {
            maxDiff = max(maxDiff, (maxi - arr[i]));
        }
    }
    return maxDiff;
}
int main() {
    int n = 6;
    int arr[n] = { 7,2,5,6,3,9 };
    int res = findMax(arr, n);
    cout << "Maximus Is : " << res << endl;
    return 0;
}