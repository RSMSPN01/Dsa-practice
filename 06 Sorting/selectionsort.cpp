#include <iostream>
#include <algorithm>
using namespace std;
void selectionSort(int arr[], int n) {

    for (int i = 0; i < n - 1; i++)
    {
        int index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[index])
            {
                index = j;
            }
        }
        if (index != i)
        {
            swap(arr[i], arr[index]);
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
    selectionSort(arr, n);
    return 0;
}