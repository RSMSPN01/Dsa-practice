#include <iostream>
using namespace std;
int digitRoot(int n) {
    if (n < 10)
    {
        return n;
    }
    int sum = (n % 10) + digitRoot(n / 10);
    if (sum < 10)
    {
        return sum;
    } else {
        return digitRoot(sum);
    }
}
int main() {
    int n;
    cin >> n;
    int res = digitRoot(n);
    cout << "Res is : " << res << endl;
    return 0;
}