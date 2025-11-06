#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int arr[5] = { 3,5,4,3,5 };
    unordered_set<int> m(arr, arr + 5);
    for (auto&& i : m)
    {
        cout << i << " ";
    }
    return 0;
}