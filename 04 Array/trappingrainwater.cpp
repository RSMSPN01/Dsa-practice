#include <iostream>
#include <algorithm>
using namespace std;
int rainWater(int arr[], int n) {
    // by using two pointer approach
    int lp = 0;
    int rp = n - 1;
    int lmax = 0;
    int rmax = 0;
    int water = 0;
    while (lp < rp)
    {
        lmax = max(lmax, arr[lp]);
        rmax = max(rmax, arr[rp]);
        if (lmax < rmax)
        {
            water += (lmax - arr[lp]);
            lp++;
        } else {
            water += (rmax - arr[rp]);
            rp--;
        }
    }
    return water;
}
int main() {
    int n = 7;
    int arr[n] = { 5,2,0,3,5,0,3 };
    int totalWater = rainWater(arr, n);
    cout << totalWater << endl;
    return 0;
}