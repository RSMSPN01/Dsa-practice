#include <iostream>
#include <algorithm>
using namespace std;
int maxWater(int height[], int n) {
    if (n < 3) { return 0; }
    int i = 0, j = n - 1, maxWater = 0;
    while (i < j)
    {
        int width = j - i - 1;
        int h = min(height[i], height[j]);
        maxWater = max(maxWater, width * h);
        (height[i] < height[j]) ? j-- : i++;
    }
    return maxWater;
}
int main() {
    int n = 6;
    int arr[n] = { 2,1,3,4,6,5 };
    cout << maxWater(arr, n);
    return 0;
}