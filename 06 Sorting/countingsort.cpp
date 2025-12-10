#include <iostream>
using namespace std;
// T.C = O(n+k) and S.C = O(n).
void countingSort(int arr[], int n) {
    int k = arr[0];
    // First thing is to find the maximum value in the array to make the k size array.
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > k)
        {
            k = arr[i]; // maximum element is stored now.
        }
    }
    k = k + 1; // To handle the size well we add one extra just in case.
    int freq[k] = { 0 }; // freq array is created to store the freq of size k.
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++; // we count all the frequencies of the values present in the array.
    }
    for (int i = 1; i < k; i++)
    {
        freq[i] += freq[i - 1]; // add the previous frequency in the current frequency.
    }
    int count[n]; // create another array to store the final result.
    for (int i = n - 1; i >= 0;i--) // starting from the reverse becuase it makes the algorithm stable in sorting.
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