#include <iostream>
using namespace std;
void unionArray(int arr1[], int arr2[], int m, int n) {
    int i = 0, j = 0, prev = -1;
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
        {
            if (arr1[i] != prev)
            {
                cout << arr1[i] << " ";
                prev = arr1[i];
            }
            i++;
        } else {
            if (arr2[j] != prev)
            {
                cout << arr2[j] << " ";
                prev = arr2[j];
            }
            j++;
        }
    }
    while (i < m)
    {
        if (arr1[i] != prev)
        {
            cout << arr1[i] << " ";
        }
        i++;
    }
    while (j < n)
    {
        if (arr2[j] != prev)
        {
            cout << arr2[j] << " ";
        }
        j++;
    }
}
int main() {
    int m = 3, n = 1;
    int arr1[m] = { 1,2,2 };
    int arr2[n] = { 3 };
    unionArray(arr1, arr2, m, n);
    return 0;
}