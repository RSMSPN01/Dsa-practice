#include <iostream>
using namespace std;
int pow(int x, int n) {
    if (n == 0)
    {
        return 1;
    }if (n == 1)
    {
        return x;
    }
    int res = 1;
    while (n != 0)
    {
        if (n & 1)
        {
            res *= x;
        }
        x *= x;
        n = n >> 1;

    }
    return res;
}
int main() {
    int x, n;
    cout << "Enter number and its power : " << endl;
    cin >> x >> n;
    int result = pow(x, n);
    cout << result;
    return 0;
}