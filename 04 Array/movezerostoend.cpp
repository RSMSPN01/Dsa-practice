#include <iostream>
using namespace std;
void moveZeros(int arr[], int n) {
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            if (i != res)
            {
                swap(arr[i], arr[res]);
            }
            res++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

}
int main() {
    int n = 6;
    int arr[n] = { 12,0,0,32,11,0 };
    moveZeros(arr, n);
    return 0;
}