#include <iostream>
using namespace std;
void hoarePartition(int arr[], int n) {
    int i = -1, j = n, pivot = arr[0];
    while (i <= j)
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
            return;
        }

        swap(arr[i], arr[j]);
    }
}
int main() {
    int n = 4;
    int arr[n] = { 4,2,8,3 };
    hoarePartition(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}