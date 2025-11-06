#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    int arr[8] = { 3,1,0,1,8,2,3,6 };
    int sum = 5, preSum = 0, cnt = 0;
    unordered_map<int, int>m;
    for (int i = 0; i < 8; i++)
    {
        preSum += arr[i];
        if (preSum == sum)
        {
            cnt = i + 1;
        }
        if (m.find(preSum) == m.end())
        {
            m.insert({ preSum,i });
        }
        if (m.find(preSum - sum) != m.end())
        {
            cnt = max(cnt, i - m[preSum - sum]);
        }
    }
    cout << cnt << endl;
    return 0;
}