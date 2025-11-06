#include <iostream>
using namespace std;
int peakElement(int arr[], int n) {
    int l = 0;
    int h = n - 1;
    int mid = 0;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (arr[mid] == 0 || arr[mid] == n - 1)
        {
            return arr[mid];
        }
        if (arr[mid] >= arr[mid - 1] && arr[mid] >= arr[mid + 1])
        {
            return arr[mid];
        }
        if (arr[mid - 1] > arr[mid])
        {
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}
int main() {
    int n = 6;
    int arr[n] = { 19,18,17,16,13,4 };
    cout << peakElement(arr, n);
    return 0;
}