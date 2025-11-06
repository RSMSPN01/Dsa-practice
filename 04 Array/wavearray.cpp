#include <iostream>
using namespace std;
void waveArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i = i + 2)
    {
        if (arr[i] < arr[i + 1])
        {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        } else if (arr[i] == n)
        {
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

}
int main() {
    int n = 6;
    int arr[n] = { 2,4,7,8,9,10 };
    waveArray(arr, n);
    return 0;
}