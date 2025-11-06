#include <iostream>
#include <math.h>
using namespace std;
void printDivisors(int n) {
    // fix the code i will do it later on ...
    if (n == 1)
    {
        cout << "1" << endl;
    }
    while (n % 2 == 0)
    {
        cout << "2" << endl;
        n /= 2;
    }
    while (n % 3 == 0)
    {
        cout << "3" << endl;
        n /= 3;
    }
    for (int i = 5; i <= sqrt(n); i += 6)
    {
        if (n % i == 0)
        {
            cout << i << endl;
        }
        if (n % (i + 2) == 0) {
            cout << i + 2 << endl;
        }

    }
}
int main() {
    int n;
    cout << "Enter the number : " << endl;
    cin >> n;
    printDivisors(n);
    return 0;
}