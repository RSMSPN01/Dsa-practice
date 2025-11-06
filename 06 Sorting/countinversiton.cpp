#include <iostream>
using namespace std;
int mergeandCount(int arr[], int start, int mid, int end) {
    int n = end - start + 1;
    int res = 0;
    int temp[n], i = start, j = mid + 1, k = 0; // give proper values to the variable i and j 
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])// to ensure the stability do this though
        {
            temp[k++] = arr[i++];
        } else {
            res = res + (mid - i + 1); // this is the formula to get inversion in this sense that if found such element
            // then all the elements in that array after that element are also going to be the inversion for that no. bcs
            // the array is in sorted manner.
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
    return res;
}
int mergeSort(int arr[], int start, int end) {
    int res = 0;
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        res += mergeSort(arr, start, mid);
        res += mergeSort(arr, mid + 1, end);
        res += mergeandCount(arr, start, mid, end);
    }
    return res;
}
int main() {
    int n = 3;
    int arr[n] = { 3,2,4 };
    cout << mergeSort(arr, 0, n - 1);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    return 0;
}