#include <iostream>
using namespace std;
int lomutoPartition(int arr[], int low, int end) {
    int pivot = arr[end], window = low - 1;
    for (int j = low; j < end; j++)
    {
        if (arr[j] < pivot)
        {
            window++;
            swap(arr[j], arr[window]);
        }
    }
    swap(arr[end], arr[window + 1]);
    return window + 1;

}
int kthSmallest(int arr[], int k, int n) {
    int low = 0, end = n - 1;
    while (low <= end)
    {
        int p = lomutoPartition(arr, low, end);
        if (p == k - 1)
        {
            return arr[p];
        } else if (p > k - 1)
        {
            end = p - 1;
        } else {
            low = p + 1;
        }
    }
}
int main() {
    int n = 6;
    int arr[n] = { 2,8,4,6,9,5 };
    int k = 4;
    cout << kthSmallest(arr, k, n);
    return 0;
}