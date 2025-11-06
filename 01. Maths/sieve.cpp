#include <iostream>
#include <vector>
using namespace std;
void printRange(int x) {
    vector <bool>v(x + 1, true);
    for (int i = 2; i * i <= x; i++)
    {
        if (v[i] == true)
        {
            for (int j = i * i; j <= x; j = j + i)
            {
                v[j] = false;
            }

        }

    }
    for (int i = 2; i < v.size(); i++)
    {
        if (v[i] == true) {
            cout << i << " ";
        }
    }
}
int main() {
    int x;
    cin >> x;
    printRange(x);
    return 0;
}