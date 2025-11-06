#include <iostream>
#include <unordered_map>
using namespace std;
// Boyer–Moore majority vote for n / k elements
// time complexity is O(n.k) and space complexity is O(k)
int main() {
    int n = 9, k = 4;
    int arr[n] = { 30,10,20,20,20,10,40,30,30 };
    unordered_map<int, int>m;
    for (int i = 0; i < n; i++)
    {
        if (m.find(arr[i]) != m.end())
        {
            m[arr[i]]++;
        } else if (m.size() < k - 1) {
            m[arr[i]] = 1;
        } else {
            for (auto it = m.begin(); it != m.end();) { // understand the loop from the chatGpt
                it->second--;
                if (it->second == 0)
                    it = m.erase(it);
                else
                    ++it;
            }
        }
    }
    for (auto&& i : m)
    {
        if (i.second >= n / k)
        {
            cout << i.first << " ";
        }

    }
    return 0;
}