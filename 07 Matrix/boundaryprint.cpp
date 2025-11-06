#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> v(4);
    int count = 1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            v[i].push_back(count);
            count++;
        }
    }
    // boundary print only
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i == 0)
            {
                cout << v[i][j] << " ";
            } else if (i != 4 - 1)
            {
                cout << v[i][4 - 1] << " ";
                break;
            } else {
                cout << v[i][4 - 1 - j] << " ";
            }
        }
    }
    for (int i = 4 - 2; i > 0; i--)
    {
        cout << v[i][0] << " ";
    }
    return 0;
}