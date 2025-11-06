#include <iostream>
using namespace std;

void countZeros(int n) {
    int count = 0;
    while (n >= 5)
    {
        count += n / 5;
        n /= 5;
    }
    cout << count;
}
int main() {
    // First Calculate the factorial then calculate its zeros but not a great opiton 
    int n;
    cout << "Enter the number : " << endl;
    cin >> n;
    countZeros(n);
    return 0;
}