#include <iostream>
#include <vector>
using namespace std;
int binarySearch(vector<int>v, int low, int high, int key) {
    int l = low, h = high, mid = 0;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key < v[mid])
        {
            h = mid - 1;
        } else if (key > v[mid])
        {
            l = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}
int infiniteSearch(vector<int>& v, int key) {
    int i = 1;
    if (key == v[0]) { return 0; }
    while (v[i] <= key)
    {
        if (v[i] == key)
        {
            return i;
        }
        i = i * 2;
    }
    return binarySearch(v, (i / 2) + 1, i, key);
}
int main() {
    vector <int> v(100);
    int key = 100;
    for (int i = 0; i < v.size(); i++)
    {
        v[i] = i + 1;
    }
    cout << infiniteSearch(v, key);
    return 0;
}