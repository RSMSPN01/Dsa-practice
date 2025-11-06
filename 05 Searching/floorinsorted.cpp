#include <iostream>
using namespace std;
int floor(int arr[], int n, int x) {
    int start = 0, end = n - 1, ans = -1, mid = 0;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] == x)
        {
            return (mid == 0) ? (-1) : arr[mid - 1];
        }
        if (arr[mid] < x)
        {
            ans = arr[mid];
            start = mid + 1;

        } else {
            end = mid - 1;
        }
    }
    return ans;
}
int main() {
    int n = 7;
    int arr[n] = { 1,2,8,10,11,12,19 };
    int x = 29;
    cout << floor(arr, n, x);
    return 0;
}