#include <iostream>
#include <algorithm>
using namespace std;
void lumutoPartition(int arr[], int n) {
    int pivot = arr[n - 1], window = -1;
    for (int j = 0; j < n - 1; j++)
    {
        if (arr[j] < pivot)
        {
            window++;
            swap(arr[j], arr[window]);
        }
    }
    swap(arr[window + 1], arr[n - 1]);

}
int main() {
    int n = 7;
    int arr[n] = { 10,80,30,90,40,50,70 };
    lumutoPartition(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}