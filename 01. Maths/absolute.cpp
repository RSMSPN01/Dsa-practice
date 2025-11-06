#include <iostream>
using namespace std;

void absolute(int n)
{
    if (n < 0) {
        cout << n * -1 << endl;
    }
    else {
        cout << n << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    absolute(n);
    return 0;
}