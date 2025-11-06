#include <iostream>
using namespace std;
int binaryGray(int n) {
    return (n ^ (n >> 1));
}
int grayBinary(int m) {
    int result = m;
    while (m > 0)
    {
        m = m >> 1;
        result = result ^ m;
    }
    return result;

}
int main() {
    int n = 0;
    cin >> n;
    int grayCode = binaryGray(n);
    cout << grayCode << endl;
    int m = 0;
    cin >> m;
    int binaryCode = grayBinary(m);
    cout << binaryCode << endl;
    return 0;
}