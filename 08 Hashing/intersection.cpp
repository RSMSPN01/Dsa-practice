#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int arr1[7] = { 10,15,20,15,30,30,5 };
    unordered_set<int> s(arr1, arr1 + 7);
    int arr2[4] = { 30,5,30,80 };
    int cn = 0;
    for (int i = 0; i < 4; i++)
    {
        if (s.find(arr2[i]) != s.end())
        {
            cn++;
            s.erase(arr2[i]);
        }

    }

    cout << cn << endl;
    return 0;
}