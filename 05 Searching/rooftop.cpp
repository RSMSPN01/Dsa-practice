#include <iostream>
using namespace std;
// i have calculate contigous steps count here.
int maxAltitudeGain(int arr[], int  n) {
    int maxElement = -1;//last element
    int steps = 0, count = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > maxElement)
        {
            maxElement = arr[i];
            steps = 0;
        } else if (arr[i] < maxElement && arr[i] < arr[i + 1])
        {
            steps++;
            count = max(count, steps);
        } else {
            steps = 0;
        }
    }
    return count;
}
int main() {
    int n = 6;
    int arr[n] = { 1,2,2,3,4,3 };
    cout << maxAltitudeGain(arr, n) << " Steps" << endl;
    return 0;
}