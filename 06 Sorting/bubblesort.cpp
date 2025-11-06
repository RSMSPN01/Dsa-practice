#include <iostream>
#include <algorithm>
using namespace std;
// time complexity is O(n^2)
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
    {
        bool isSwapable = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                isSwapable = true;
                swap(arr[j], arr[j + 1]);
            }
        }
        if (!isSwapable)
        {
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main() {
    int n = 6;
    int arr[n] = { 5,8,1,0,4,2 };
    bubbleSort(arr, n);
    return 0;
}