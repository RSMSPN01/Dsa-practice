#include <iostream>
using namespace std;
bool checkforPow(int n) {
    // return (n & (n - 1));
    if (n <= 0)
    {
        return false;
    }

    if (n == 1)
    {
        return true;
    }
    return checkforPow(n / 2);

}
int main() {
    int n;
    cin >> n;
    if (checkforPow(n))
    {
        cout << "Ture" << endl;
    } else {
        cout << "False" << endl;
    }
    (n);
    return 0;
}