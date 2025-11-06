#include <iostream>
using namespace std;
void insertinArray(int arr[], int n, int v, int in) {
    int temp = arr[in]; // 4 is store here.
    arr[in] = v;
    for (int i = in + 1; i < n; i++)
    {
        int temp2 = arr[i];
        arr[i] = temp;
        temp = temp2;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }


}
int main() {
    int n = 5;
    int arr[n] = { 1,2,4,5 };
    int value = 3;
    int index = 2;
    insertinArray(arr, n, value, index);
    return 0;
}