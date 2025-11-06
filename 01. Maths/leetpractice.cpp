#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    vector <int>v(3, 0);
    cout << v.size() << endl;
    for (int i = 0; i <= v.size(); i++)
    {
        v[i] = i;
    }

    cout << v.size() << endl;
    for (int i = 0; i <= v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << v.size() << endl;
    v.insert(v.begin(), 9);
    for (int i = 0; i <= v.size(); i++)
    {
        cout << "Second time " << v[i] << " ";
    }
    cout << v.size();
    
    return 0;
}