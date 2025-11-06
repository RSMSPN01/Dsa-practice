#include <iostream>
using namespace std;
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main() {
    int n = 6;
    int arr[n] = { 5,8,1,0,4,2 };
    insertionSort(arr, n);
    return 0;
}