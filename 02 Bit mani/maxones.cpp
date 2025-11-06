#include <iostream>
#include <algorithm>
using namespace std;
int mostconsecutiveOnes(int n) {
    if (n == 0)
    {
        return 0;
    }
    int count = 1;
    int maxi = 1;
    for (int i = 0; i < 32; i++)
    {
        if ((n & (1 << i)) && (n & (1 << 1 + i)))
        {
            count++;
            maxi = max(maxi, count);
        } else {
            if (count != 1)
            {
                count = 1;
            }
        }
    }
    return maxi;
}
int main() {
    int n;
    cin >> n;
    int caught = mostconsecutiveOnes(n);
    cout << "Maximum No. of Consecutive One's are : " << caught << endl;
    return 0;
}