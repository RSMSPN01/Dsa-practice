#include <iostream>
using namespace std;
// revise the more optimized approach (n&(n<<1)!=0)
bool checkSparse(int n) {
    for (int i = 0; i < 31; i = i + 2)
    {
        if ((n & (1 << i)) && (n & (1 << (i + 1))))
        {
            return false;
        }

    }
    return true;

}
int main() {
    int n;
    cin >> n;
    if (checkSparse(n)) {
        cout << "Given Number : " << n << " is a sparse." << endl;
    } else {
        cout << "Given Number : " << n << " is not a sparse." << endl;
    }
    return 0;
}