#include <iostream>
using namespace std;
bool isPair(int arr[], int n, int value) {
    int l = 0;
    int h = n - 1;
    while (l < h)
    {
        int sum = arr[l] + arr[h];
        if (sum == value)
        {
            cout << arr[l] << " " << arr[h] << endl;
            return true;
        }
        if (sum > value)
        {
            h--;
        } else {
            l++;
        }
    }
    return false;
}
int main() {
    int n = 7;
    int arr[n] = { 2,4,5,8,10,12,24 };
    int value = 18;
    cout << isPair(arr, n, value);
    return 0;
}