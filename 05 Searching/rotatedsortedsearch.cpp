#include <iostream>
using namespace std;
// int binarySearch(int arr[], int n, int key) {
    // int l = 0, h = n - 1, mid = 0;

    // while (l <= h)
    // {
    //     mid = (l + h) / 2;
    //     if (key == arr[mid])
    //     {
    //         return mid;
    //     } else if (key >= arr[l] && key <= arr[mid])
    //     {
    //         h = mid - 1;
    //     } else {
    //         l = mid + 1;
    //     }
    // }
    // return -1;
// }
// this code also works fine for many of the test cases not all i don't even know how
int binarySearch(int arr[], int n, int key) {
    int l = 0, h = n - 1, mid = 0;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr[mid])
        {
            return mid;
        } else if (arr[l] <= arr[mid])
        {
            if (key >= arr[l] && key <= arr[mid])
            {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        } else {
            if (key >= arr[mid] && key <= arr[h])
            {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
    }
    return -1;
}
int main() {
    int n = 10, key = 40;
    int arr[n] = { 50,60,70,80,90,100,10,20,30,40 };
    cout << binarySearch(arr, n, key);
    return 0;
}