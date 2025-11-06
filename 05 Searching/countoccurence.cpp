#include <iostream>
using namespace std;
// there could be many improvment done on this code so please wait and understand
// if you can't then do chatgpt he will tell the answers
int firstOccurence(int arr[], int n, int key) {
    int l = 0;
    int h = n - 1;
    int mid = 0;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key < arr[mid])
        {
            h = mid - 1;
        } else if (key > arr[mid])
        {
            l = mid + 1;
        } else {
            if (arr[mid] != arr[mid - 1] || mid == 0)
            {
                return mid;
            } else {
                h = mid - 1;
            }
        }
    }
    return -1;
}
int lastOccurence(int arr[], int n, int key) {
    int l = 0;
    int h = n - 1;
    int mid = 0;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key < arr[mid])
        {
            h = mid - 1;
        } else if (key > arr[mid])
        {
            l = mid + 1;
        } else {
            if (arr[mid] != arr[mid + 1] || mid == n - 1)
            {
                return mid;
            } else {
                l = mid + 1;
            }
        }
    }
    return -1;
}
int countOccurence(int arr[], int n, int key) {
    return ((firstOccurence(arr, n, key) >= 0) ? lastOccurence(arr, n, key) - firstOccurence(arr, n, key) + 1 : -1);
}
int main() {
    int n = 7;
    int key = 1;
    int arr[n] = { 1,1,2,3,4,4,4 };
    cout << countOccurence(arr, n, key);
    return 0;
}