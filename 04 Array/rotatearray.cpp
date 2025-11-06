#include <iostream>
using namespace std;
void rotateArray(int arr[], int n, int d) {
    if (d == n || n == 0 || d == 0) {
        //return the same array no changes need to be done.
        cout << "The array is just the same";
        return;
    }
    if (d > n) { // making a valid size for d.
        while (d >= n)
        {
            d = d % n;
        }
    }
    int helparray[d]; // putting the values in the secondary array.
    for (int i = 0; i < d; i++)
    {
        helparray[i] = arr[i];
    }
    for (int i = d; i < n; i++)
    {
        arr[i - d] = arr[i];
    }
    int j = n - 1;
    for (int i = d - 1; i >= 0; i--, j--)
    {
        arr[j] = helparray[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }


}
int main() {
    int n = 5;
    int arr[n] = { 2,5,7,9,1 };
    int d = 0;
    cin >> d;
    rotateArray(arr, n, d);
    return 0;
}