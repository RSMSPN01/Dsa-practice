// lets assume we have 32bit system and we wan't to reverse the number
// but here is a catch if number is greater then 32bit then return zero
#include <iostream>
#include <climits>
using namespace std;
int reverse(int x) {
    int r = 0;
    while (x) {
        int digit = x % 10;
        x /= 10;

        if (r > INT_MAX / 10 || (r == INT_MAX / 10 && digit > 7))
            return 0;
        if (r < INT_MIN / 10 || (r == INT_MIN / 10 && digit < -8))
            return 0;
        // so why we use INT_MAX/10 here the thing is that if a number / 10 is already big then intmax/10 then
        // it will definately overflow when we multiply it with 10 so before multiplication we check it before 
        // to handle it already before even multiplying it.
        // now why to use digits to check the thing is the last vale in intmax is from 0 to 6 so if there is last digit
        // which only wants to store a number between 0 to 7 we can let it happen but if any number is greater than 7
        // is not allowed and similarly for the negative case no less number then -8 
        r = r * 10 + digit;
    }
    return r;
}
int main() {
    cout << reverse(-23145);
    return 0;
}