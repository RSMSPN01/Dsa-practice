#include <iostream>
using namespace std;
bool checkSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}
int main() {
    int n = 5;
    int arr[n] = { 12,15,13,19,20 };
    if (checkSort(arr, n)) {
        cout << "Array is Sorted" << endl;
    } else {
        cout << "Array is not Sorted" << endl;
    }
    return 0;
}