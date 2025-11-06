#include <iostream>
using namespace std;
void maxHeap(int arr[], int n, int i) {
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left<n && arr[left]>arr[largest])
    {
        largest = left;
    }
    if (right<n && arr[right]>arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        maxHeap(arr, n, largest);
    }

}
void buildHeap(int arr[], int n) {
    for (int i = (n - 2) / 2; i >= 0; i--)
    {
        maxHeap(arr, n, i);
    }
}
void heapSort(int arr[], int n) {
    buildHeap(arr, n);
    for (int i = n - 1; i > 0; i--) 
    {
        swap(arr[i], arr[0]);
        maxHeap(arr, i, 0);
    }

}
int main() {
    int n = 7;
    int arr[n] = { 7,6,5,4,3,2,1 };
    heapSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}