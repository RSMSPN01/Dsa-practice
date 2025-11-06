#include <iostream>
#include <climits>
using namespace std;
int checkIfRotated(int arr[], int n) {
    //count the number of time it is rotated.
    int minElement = INT_MAX;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < minElement)
        {
            minElement = arr[i];
            index = i;
        }
    }
    if (index == 0)
    {
        return 0;
    } else {
        return n - index;
    }


}
int main() {
    int n = 5;
    int arr[n] = { 2,3,4,5,1 };
    // given constrains
    // The array is confirmed sorted and may or may not be sorted 
    // The sorting is done <n
    cout << checkIfRotated(arr, n);
    return 0;
}