#include <iostream>
using namespace std;
int sqrt(int x) {
    int l = 1, h = x, mid = 0, ans = 0;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if ((mid * mid) == x)
        {
            return mid;
        } else if (x < (mid * mid))
        {
            h = mid - 1;
        } else {
            ans = mid;
            l = mid + 1;
        }
    }
    return ans;
}
int main() {
    int x = 4;
    cout << sqrt(x);
    return 0;
}