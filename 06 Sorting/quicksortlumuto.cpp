#include <iostream>
using namespace std;
int lumutoPartition(int arr[], int low, int high) {
    // pivot is always the last element of the array
    int i = low - 1, pivot = arr[high];
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1; // always return i+1 because i is never incremented by one it is still at the last elemet < pivot;
}
void quickSort(int arr[], int l, int h) {
    if (l < h)
    {
        int p = lumutoPartition(arr, l, h);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, h);
    }

}
int main() {
    int n = 7;
    int arr[n] = { 8,4,7,9,3,10,5 };
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}