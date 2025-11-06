#include <iostream>
using namespace std;
void binarySearch(int arr[], int n, int key) {
    int l = 0;
    int h = n - 1;
    int mid = 0;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr[mid])
        {
            cout << "Key found at : " << mid;
            return;
        } else if (key < arr[mid]) {
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << "Key not Found in the Array.";
}
int main() {
    int n = 9;
    int key = 12;
    int arr[n] = { 2,12,14,16,20,25,32,38,49 };
    binarySearch(arr, n, key);
    return 0;
}