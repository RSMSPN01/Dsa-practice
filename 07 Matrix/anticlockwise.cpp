#include <iostream>
using namespace std;

int main() {
    int n = 3;
    int arr[][n] = { {1,2,3},{4,5,6},{7,8,9} };
    // even this code only works for the nxn matrix and don't for uneven matrixes
    // for uneven matrix you need to take extra space to store the result first

    //transpose of the matrix
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
    // reverse each columns
    for (int i = 0; i < (n - 1) / 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            swap(arr[i][j], arr[n - i - 1][j]);
        }
    }
    // print the array
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