#include <iostream>
using namespace std;
void reverse(string s, int n, int i = 0) {
    if (i == n)
    {
        return;
    }
    reverse(s, n, i + 1);
    cout << s[i];

}
int main() {
    string s = "hello";\
        int n = s.length();
    reverse(s, n);
    return 0;
}