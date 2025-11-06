#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector <int>v = { 5,4,4,3,2,1,2,3 };
    int x = 0;
    for (auto&& i : v)
    {
        x ^= i;
    }
    int setBit = 0;
    for (int i = 0; i < 32; i++)
    {
        if (x & (1 << i))
        {
            setBit = i;
        }
    }
    int setbit = 0;
    int notSetBit = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] & (1 << setBit))
        {
            setbit ^= v[i];
        } else {
            notSetBit ^= v[i];
        }
    }
    cout << setbit << " " << notSetBit << endl;
    return 0;
}