#include <iostream>
using namespace std;
void findElement(int arr[][4], int x) {
    int i = 0, j = 4 - 1;
    while (i < 4 && j >= 0)
    {
        if (arr[i][j] == x)
        {
            cout << "Element found at (" << i << " " << j << ")";
            return;
        } else if (x < arr[i][j])
        {
            j--;
        } else {
            i++;
        }
    }
    cout << "Element is not present";
}
int main() {
    // sorted matrix row and column wise.
    int row = 4, col = 4;
    int arr[][4] = {
            {10,20,30,40},
            {15,25,35,45},
            {27,29,37,48},
            {32,33,39,50} };
    int x = 29;
    findElement(arr, x);
    return 0;
}