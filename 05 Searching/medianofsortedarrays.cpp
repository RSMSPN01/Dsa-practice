#include <iostream>
#include <vector>
#include <climits>
using namespace std;
double findMedian(vector<int>& v1, vector<int>& v2) {
    // l0 l1|| r1 r0 v1[]
    // l0 l1|| r2 r0 v2[]
    // This code is also submitted in the leetcode so do check that out too .
    // look for the video by striver
    int n1 = v1.size(), n2 = v2.size();
    int n = n1 + n2;// for checking even or odd;
    if (n1 > n2)// size check (apply binary search on smaller array)
    {
        return findMedian(v2, v1); // don't forget to return this else it will give RTE
    }
    int leftSize = (n1 + n2 + 1) / 2; // no. of elements to be stored in the left side
    int start = 0, end = n1, mid1 = 0, mid2 = 0;
    while (start <= end)
    {
        mid1 = start + (end - start) / 2;
        mid2 = leftSize - mid1;
        int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < n1) { r1 = v1[mid1]; }
        if (mid2 < n2) { r2 = v2[mid2]; }
        if (mid1 - 1 >= 0) { l1 = v1[mid1 - 1]; }
        if (mid2 - 1 >= 0) { l2 = v2[mid2 - 1]; }
        if (l1 <= r2 && l2 <= r1)
        {
            if (n & 1) { return (double)max(l1, l2); } // if odd then do this
            else {
                return ((double)(max(l1, l2) + min(r1, r2)) / 2.0); // if even do this 
            }
        }
        if (l1 > r2)
        {
            end = mid1 - 1;
        } else {
            start = mid1 + 1;
        }
    }
    return 0;
}
int main() {
    vector <int>v1 = { 1,3,5,7 };
    vector <int>v2 = { 2,4,6,8,10 };
    cout << findMedian(v1, v2);
    return 0;
}