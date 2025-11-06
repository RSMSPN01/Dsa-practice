#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int even_mask = 0x55555555;
    int odd_mask = 0xAAAAAAAA;
    int  even = (n & 0x55555555);
    int odd = (n & 0xAAAAAAAA);
    even <<= 1;
    odd >>= 1;
    n = even | odd;
    cout << n;


    return 0;
}