#include <iostream>
#include <math.h>
using namespace std;
int digitSum(int n) {
    if (n <= 0) {
        return 0;
    }
    return n % 10 + digitSum(n / 10);
}
int main() {
    int n;
    cout << "Enter a number : " << endl;
    cin >> n;
    int result = digitSum(n);
    cout << "Sum is : " << result << endl;

    return 0;
}