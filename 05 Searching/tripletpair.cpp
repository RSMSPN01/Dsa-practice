#include <iostream>
using namespace std;
bool isPair(int arr[], int n, int value, int low) {
    int l = low;
    int h = n - 1;
    while (l < h)
    {
        int sum = arr[l] + arr[h];
        if (sum == value)
        {
            cout << arr[l] << " " << arr[h] << " ";
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
    int n = 9;
    int arr[n] = { 2,4,11,13,15,21,23,25,30 };
    int value = 59;
    for (int i = 0; i < n; i++)
    {
        if (isPair(arr, n, value - arr[i], i + 1)) {
            cout << arr[i] << endl;
            break;
        } else {
            cout << "No pair Baby";
        }
    }

    return 0;
}