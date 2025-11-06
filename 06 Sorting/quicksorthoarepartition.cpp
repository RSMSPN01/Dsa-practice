#include <iostream>
using namespace std;
int hoarePartition(int arr[], int low, int high) {
    int i = low - 1, j = high + 1, pivot = arr[low];
    while (true)
    {
        do
        {
            i++;
        }
        while (arr[i] < pivot);
        do
        {
            j--;
        }
        while (arr[j] > pivot);
        if (i >= j)
        {
            return j;
        }
        swap(arr[i], arr[j]);
    }
}
void quickSort(int arr[], int l, int h) {
    if (l < h)
    {
        int p = hoarePartition(arr, l, h);
        quickSort(arr, l, p);
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