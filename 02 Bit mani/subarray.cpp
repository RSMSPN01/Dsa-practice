#include <iostream>
#include <math.h>
using namespace std;

int main() {
    string s = "abc";
    int n = s.length();
    int power = pow(2, n);
    for (int i = 0; i < power; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                cout << "'" << s[j] << "'";
            }

        }
        cout << endl;
    }

    return 0;
}