#include <iostream>
using namespace std;
void towerHanoi(int n, string src, string help, string dest) {
    if (n == 1)
    {
        cout << "Ring " << n << " is moved from " << src << " to " << dest << endl;
        return;
    }

    towerHanoi(n - 1, src, dest, help);
    cout << "Ring " << n - 1 << " is moved from " << src << " to " << dest << endl;
    towerHanoi(n - 1, help, src, dest);
}
int main() {
    int n = 0;
    cin >> n;
    string s, h, d;
    cin >> s >> h >> d;
    towerHanoi(n, s, h, d);
    return 0;
}