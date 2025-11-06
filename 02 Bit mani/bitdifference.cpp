#include <iostream>
using namespace std;
// count the bit difference for non neg and non zero numbers.
void bitDifference(int n, int m) {
    int diff = n ^ m;
    // count set bits
    int count = 0;
    while (diff != 0)
    {
        diff = diff & (diff - 1);
        count++;
    }
    cout << "Bit Difference is : " << count;
}
int main() {
    int n, m;
    cin >> n >> m;
    if (n == m) {
        cout << "Bit Difference is : 0" << endl;
    } else {
        bitDifference(n, m);
    }
    return 0;
}