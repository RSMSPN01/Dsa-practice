#include <iostream>
using namespace std;
void merge(int arr[], int start, int mid, int end) {
    int n = end - start + 1;
    int temp[n], i = start, j = mid + 1, k = 0; // give proper values to the variable i and j 
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])// to ensure the stability do this though
        {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= end) {
        temp[k++] = arr[j++];
    }
    for (int l = 0; l < n; l++)
    {
        arr[l + start] = temp[l]; // please remember this one use start because start is not always starts from index zero
    }
}
void mergeSort(int arr[], int start, int end) {
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}
int main() {
    int n = 9;
    int arr[n] = { 23,12,9,21,8,34,10,17,37 };
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}