#include <iostream>
#include <unordered_set>
using namespace std;
// please make notes for this code in the end

int main() {
    int arr[3] = { 11,5,6 };
    int sum = 10, flag = 0;
    unordered_set<int>s;
    s.insert(arr[0]);
    for (int i = 1; i < 3; i++)
    {
        if (s.find(sum - arr[i]) != s.end())
        {
            flag = 1;
            break;
        } else {
            s.insert(arr[i]);
        }
    }
    if (flag) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}