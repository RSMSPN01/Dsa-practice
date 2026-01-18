#include <iostream>
using namespace std;
// Approach : So Direct approach of using the bs here on the n itself and keep storing the 
// previous smallest number bcs there could be chances that it could be the possible ans

int floorSqrt(int n) {
    int start = 0, end = n, mid = 0;
    int ans = 0;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (mid * mid == n)
        {
            return mid;
        } else if (mid * mid > n) {
            // reduce the number
            end = mid - 1;
        } else {
            ans = mid;
            start = mid + 1;
        }
    }
    return ans;

}
int main() {
    int n = 2025;
    cout << floorSqrt(n);
    return 0;
}