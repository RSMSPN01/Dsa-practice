#include <iostream>
using namespace std;
void binarySearch(int arr[], int key, int low, int high) {
    if (low > high)
    {
        cout << "Key is not Found " << endl;
        return;
    }
    int mid = (low + high) / 2;
    if (key == arr[mid])
    {
        cout << "key found at Index : " << mid << endl;
        return;
    }
    if (key < arr[mid])
    {
        binarySearch(arr, key, low, mid - 1);
    } else {
        binarySearch(arr, key, mid + 1, high);
    }
}
int main() {
    int n = 9;
    int key = 13;
    int arr[n] = { 2,12,14,16,20,25,32,38,49 };
    binarySearch(arr, key, 0, n - 1);
    return 0;
}