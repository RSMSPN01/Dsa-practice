#include <iostream> 
#include<math.h>
using namespace std;
int countDigit(int n) {
    if (n == 0)
    {
        return 0;
    } else {
        return (log10(n) + 1);
    }
}
int main() {
    int n;
    cin >> n;
    int res = countDigit(n);
    cout << res;
    return 0;
}