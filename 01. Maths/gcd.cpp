#include <iostream>
using namespace std;

void gcd(int a, int b) {
    int r = 0;
    while (a != 0)
    {
        r = b % a;
        b = a;
        a = r;
    }
    cout << "GCD is : " << b;
}
int main() {
    int a, b;
    cout << "Enter Numbers to Calculate GCD : " << endl;
    cin >> a >> b;
    gcd(a, b);
    return 0;
}