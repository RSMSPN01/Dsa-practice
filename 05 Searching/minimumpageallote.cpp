#include <iostream>
using namespace std;
bool isValid(int arr[], int n, int k, int mid) {
    int students = 1, pages = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
        {
            return false;
        }
        if (arr[i] + pages <= mid)
        {
            pages += arr[i];
        } else {
            students++;
            pages = arr[i];
        }
    }
    return (students <= k) ? true : false;
}
int allocateBooks(int arr[], int n, int k) {
    if (k > n) { return -1; }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if (k == 1) { return sum; }
    // bs from zero to sum(max pages to read)
    int start = 0, end = sum, mid = 0, ans = -1;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (isValid(arr, n, k, mid)) {
            ans = mid;
             end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return ans;
}
int main() {
    int n = 3;
    int arr[n] = { 15,17,20 };
    int k = 2;
    cout << allocateBooks(arr, n, k);
    return 0;
}