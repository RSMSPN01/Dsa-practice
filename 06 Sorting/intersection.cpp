#include <iostream>
using namespace std;
void intersectionPoints(int arr1[], int  arr2[], int  m, int  n) {
    int i = 0, j = 0, prev = -1;
    while (i < m && j < n)
    {
        if ((arr1[i] == arr2[j]) && prev != arr1[i])
        {
            cout << arr1[i] << " ";
            prev = arr1[i];
            i++;j++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else {
            j++;
        }
    }
}
int main() {
    int m = 8, n = 4;
    int arr1[m] = { 3,5,10,10,10,15,15,20 };
    int arr2[n] = { 5,10,10,15,30 };
    intersectionPoints(arr1, arr2, m, n);
    return 0;
}