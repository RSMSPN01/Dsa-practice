#include <iostream>
using namespace std;
void countSetBits(int n) {
    int count = 0;
    while (n != 0)
    {
        n = n & (n - 1);
        count++;
    }
    cout << "Total Set bits Are : " << count << endl;
}
int main() {
    int n = 0;
    cout << "Enter your Number : " << endl;
    cin >> n;
    countSetBits(n);
    return 0;
}