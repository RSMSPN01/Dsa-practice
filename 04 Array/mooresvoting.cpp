#include <iostream>
using namespace std;
int maxFreq(int arr[], int n) {
    int freq = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (freq == 0)
        {
            ans = arr[i];
        }
        if (ans == arr[i])
        {
            freq++;
        } else {
            freq--;
        }
    }
    // if not exists then 
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ans)
        {
            count++;
        }
    }
    if (count > n / 2)
    {
        return ans;
    } else {
        return -1;
    }


}
int main() {
    int n = 6;
    int arr[n] = { 1,1,2,1,4,1 };
    cout << maxFreq(arr, n);
    return 0;
}