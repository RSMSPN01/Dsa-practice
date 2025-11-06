#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[4] = { 1,1,1,1 };
    int n = 4;
    // i will not write the code for this one this is the just the copy of the previous
    // writen code just an extension of longestSubarraysum 
    // just one trick to know in this mark zero as -1.


    // int maxCnt = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     int count0 = 0, count1 = 0;
    //     for (int j = i; j < n; j++)
    //     {
    //         if (arr[j] == 0) { count0++; }
    //         if (arr[j] == 1) { count1++; }
    //         if (count0 == count1)
    //         {
    //             maxCnt = max(maxCnt, count0 + count1);
    //         }

    //     }
    // }
    // cout << maxCnt << endl; // works in O(n^2) but it works :)

    return 0;
}