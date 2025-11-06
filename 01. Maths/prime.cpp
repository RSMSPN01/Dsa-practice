#include <iostream>
#include <math.h>
using namespace std;
bool checkisPrime(int n) {
    if (n == 1)
    {
        return 0;
    }

    if (n == 2 || n == 3)
    {
        return 1;
    }
    if (n % 2 == 0 || n % 3 == 0)
    {
        return 0;
    }

    for (int i = 5; i <= sqrt(n); i = i + 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return 0;
        }
    }
    return 1;

}
int main() {
    int n;
    cout << "Enter the number : " << endl;
    cin >> n;
    if (checkisPrime(n)) {
        cout << "True";
    }
    else {
        cout << "False";
    }
    return 0;
}