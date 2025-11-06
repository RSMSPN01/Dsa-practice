#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n = 5;
    int arr[n] = { 3, 8, 4, 5, 7 };
    int maxCount = 0;

    unordered_set<int> s(arr, arr + n);

    for (int i = 0; i < n; i++) {
        if (s.find(arr[i] - 1) == s.end()) {
            int count = 1;
            int curr = arr[i];
            while (s.find(curr + 1) != s.end()) {
                curr++;
                count++;
            }
            maxCount = max(maxCount, count);
        }
    }

    cout << maxCount << endl;
    return 0;
}
