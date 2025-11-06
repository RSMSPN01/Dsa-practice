#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[5] = { 9,2,2,9,3 };
    int res = 0;
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        res = res ^ arr[i];
    }
    cout << "Odd one is : " << res;
    return 0;
}