#include <iostream>
using namespace std;
void subStr(string s, string curr, int i = 0) {
    if (i == s.length())
    {
        cout << '"' << curr << '"' << " ";
        return;
    }
    subStr(s, curr, i + 1);
    subStr(s, curr + s[i], i + 1);

}
int main() {
    string s = "abc";
    string curr = "";
    subStr(s, curr);
    return 0;
}