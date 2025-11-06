#include <iostream>
using namespace std;
int calculateGcd(int a, int b) {
    int r = 0;
    while (a != 0)
    {
        r = b % a;
        b = a;
        a = r;

    }
    return b;

}
int main() {
    int a, b;
    cout << "Enter two Numbers to calculate LCM : " << endl;
    cin >> a >> b;
    int gcd = calculateGcd(a, b);
    // cout << "GCD is : " << gcd << endl;
    int lcm = 0;
    lcm = (a * b) / gcd;
    cout << "LCM of the Numbers are : " << lcm;
    return 0;
}