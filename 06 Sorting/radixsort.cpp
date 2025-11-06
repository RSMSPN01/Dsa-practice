#include <iostream>
using namespace std;
void countingSort(int arr[], int n, int exp) {
    int freq[10] = { 0 };
    for (int i = 0; i < n; i++)
    {
        freq[(arr[i] / exp) % 10]++; // use the last digits to store the frequencies 
    }
    // prefix sum calculate
    for (int i = 1; i < 10; i++)
    {
        freq[i] += freq[i - 1];
    }
    // final output array
    int count[n];
    for (int i = n - 1; i >= 0; i--)
    {
        count[freq[(arr[i] / exp) % 10] - 1] = arr[i];
        freq[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = count[i];
    }
}
void radixSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max) {
            max = arr[i]; // max element is here now (319)
        }
    }
    // calculate digits in a way it also helps further
    for (int exp = 1; max / exp > 0; exp = exp * 10)
    {
        countingSort(arr, n, exp);
    }
}
int main() {
    int n = 6;
    int arr[n] = { 319,212,6,8,100,50 };
    radixSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}