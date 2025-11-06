#include <iostream>
#include <algorithm>
using namespace std;
bool comparator(int a, int b) {
    return (a & 1) ? b : a;
}
void sorting(int arr[], int n) {
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main() {
    int n = 4;
    int arr[n] = { 15,13,12,14 };
    sorting(arr, n);
    return 0;
}