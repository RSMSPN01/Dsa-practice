#include <iostream>
using namespace std;

int main() {
    int n = 3;
    int arr[][n] = { {1,2,3},{4,5,6},{7,8,9} };
    // this only works when you have the matrix of same order so it works without taking any extra matrix.
    // if the matrix is of uneven order then you have to take some extra space.

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}