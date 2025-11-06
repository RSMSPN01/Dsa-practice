#include <iostream>
using namespace std;
bool checkIfRotated(int arr[], int n) {
    int peak = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[(i + 1) % n]) // to check for decreasing order just do arr[i] <arr[i+1];
        {
            peak++;
        }
    }
    if (peak == 1)
    {
        return true;
    } else {
        return false;
    }
}
int main() {
    int n = 5;
    int arr[n] = { 3,4,5,1,2 };
    cout << checkIfRotated(arr, n);

    return 0;
}