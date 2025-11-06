#include <iostream>
using namespace std;
void lastOccurence(int arr[], int n, int key) {
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
                cout << "last occurence is at index : " << mid << endl;
                return;
            } else {
                l = mid + 1;
            }
        }
    }
    cout << "Key not found at any index." << endl;
    return;
}
int main() {
    int n = 9;
    int key = 20;
    int arr[n] = { 2,12,12,12,20,20,20,38,49 };
    lastOccurence(arr, n, key);
    return 0;
}