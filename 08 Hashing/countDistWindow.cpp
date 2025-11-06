#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n = 4, k = 2;
    int arr[n] = { 10,20,30,40 };
    unordered_map<int, int>m;
    for (int i = 0; i < k; i++)
    {
        m[arr[i]]++;
    }
    cout << m.size() << " ";
    for (int i = k; i < n; i++)
    {
        if (m[arr[i - k]] == 1)
        {
            m.erase(m.find(arr[i - k]));
        } else {
            m[arr[i - k]]--;
        }
        m[arr[i]]++;
        cout << m.size() << " ";
    }
    return 0;
}