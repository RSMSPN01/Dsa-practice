#include <iostream>
using namespace std;
bool checkBit(int n, int k) {
    return (1 << (k - 1) & n);
}
int main() {
    int k = 0;
    int n = 8; // 0101
    cin >> k;
    if (checkBit(n, k)) {
        cout << "True";
    } else {
        cout << "False";
    }
    return 0;
}