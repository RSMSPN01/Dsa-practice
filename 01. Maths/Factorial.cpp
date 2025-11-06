#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    unsigned long long int sum = 1;
    for (int i = 1; i <= n; i++)
    {
        sum *= i;
    }
    cout << sum << endl;
    unsigned long long int count = log10(sum) + 1;
    cout << count;
    return 0;
}