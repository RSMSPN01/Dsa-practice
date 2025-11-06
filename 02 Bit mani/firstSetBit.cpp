#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter your Number : " << endl;
    cin >> n;
    for (int i = 0; i < 32; i++)
    {
        if (n & (1 << i))
        {
            cout << i; // note that i am starting the bit count from zero.
            break;
        }
    }

    return 0;
}