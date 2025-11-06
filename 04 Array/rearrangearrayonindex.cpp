#include <iostream>
using namespace std;
void reaarangeArray(int arr[], int n) {
    // arr[i] = arr[arr[i]]  // rearrange this way
    // store two values at the same index;
    int max = n;
    for (int i = 0; i < n; i++)
    {
        arr[i] = (arr[arr[i]] % max) * max + arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] /= max;
    }
}
int main() {
    int n = 5;
    int arr[n] = { 4,0,2,1,3 };
    reaarangeArray(arr, n);
    for (auto&& i : arr)
    {
        cout << i << " ";
    }

    return 0;
}