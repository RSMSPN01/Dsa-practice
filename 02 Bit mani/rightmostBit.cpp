#include <iostream>
using namespace std;
int checkRightBit(int n, int m) {
    // int min = (n < m) ? n : m;
    // int max = (n > m) ? n : m;
    // int count = 0;
    // while (min != 0)
    // {
    //     if ((min & 1) != (max & 1))
    //     {
    //         return count;
    //     }
    //     count++;
    //     min >>= 1;
    //     max >>= 1;
    // }
    // return -1;\
    // the approach i have just used here is very wrong it can't tell the 
    // exact location for some bits so use XOR in this one if you want//
    // to get the perfect answer for this one.
}
int main() {
    int n, m;
    cout << "Enter the two numbers : " << endl;
    cin >> n >> m;
    cout << endl;
    int final = checkRightBit(n, m);
    cout << final << " bit from right is different.";
    return 0;
}