#include <iostream>
using namespace std;

int main() {
    int n = 7;
    int arr[n] = { 1,2,3,4,5,0,0 };
    int pos, value;
    cin >> pos >> value;
    int index = pos - 1;
    for (int i = n - 1; i > index; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }


    return 0;
}