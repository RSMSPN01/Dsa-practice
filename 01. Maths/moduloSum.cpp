#include <iostream>
using namespace std;
const int mod = 1e9 + 7;
void sumModulo(int a, int b) {
    int c = 0;
    c = ((a % mod) + (b % mod)) % mod;
    cout << "Sum is : " << c << endl;
}
void mulModulo(int a, int b) {
    int c = 0;
    c = (1LL * a * b) % mod;
    cout << "Mul is : " << c;
}
int main() {
    int a;
    int b;
    cin >> a >> b;
    // sum under the modulo;
    sumModulo(a, b);
    mulModulo(a, b);
    return 0;
}