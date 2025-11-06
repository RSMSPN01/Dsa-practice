#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int arr[6] = { 10,20,20,10,30,30 };
    unordered_map<int, int>m;
    for (int i = 0; i < 6; i++)
    {
        m[arr[i]]++;
    }
    for (auto&& i : m)
    {
        cout << i.first << " " << i.second << endl;
    }


    return 0;
}