#include <iostream>
using namespace std;
void reverseArray(int arr[], int n) {
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    for (int k = 0; k < n; k++)
    {
        cout << arr[k] << " ";
    }
}
int main() {
    int n = 5;
    int arr[n] = { 5,4,9,7,8 };
    reverseArray(arr, n);
    return 0;
}