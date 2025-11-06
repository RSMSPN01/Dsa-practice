#include <iostream>
using namespace std;

int main() {
    int m = 3, n = 4;
    int arr[m][n] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!(i & 1))
            {
                cout << arr[i][j] << " ";
            } else {
                cout << arr[i][n - 1 - j] << " ";
            }
        }
    }

    return 0;
}