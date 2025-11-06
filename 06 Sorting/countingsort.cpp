#include <iostream>
using namespace std;
void countingSort(int arr[], int n) {
    int k = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > k)
        {
            k = arr[i];
        }
    }
    k = k + 1;
    int freq[k] = { 0 };
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    for (int i = 1; i < k; i++)
    {
        freq[i] += freq[i - 1];
    }
    int count[n];
    for (int i = n - 1; i >= 0;i--)
    {
        count[freq[arr[i]] - 1] = arr[i];
        freq[arr[i]]--;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = count[i];
    }
}
int main() {
    int n = 6;
    int arr[n] = { 1,2,3,1,2,4 };
    countingSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}