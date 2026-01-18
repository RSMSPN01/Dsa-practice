// Approach : Naive way is by using linear search method but we can do faster by using bs search
// This is similar to the finding root of the number just a few twicks and we are good to go.

// The pow() can also give larger values so rather then using this we can also do this thing man-
// ually to prevent overflow in some cases with larger values. 

#include <iostream>
#include <math.h>
using namespace std;
int NthRoot(int N, int M) {
    // edge case to handle
    if (N == 1) {
        return M;
    }
    int start = 0, end = M, mid = 0;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (pow(mid, N) == M)
        {
            return mid;
        } else if (pow(mid, N) > M) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return -1;
}
int main() {
    int n = 4, m = 81;
    cout << NthRoot(n, m);
    return 0;
}