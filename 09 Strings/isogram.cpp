#include <iostream>
using namespace std;
bool isogramOrNot(string& s) {
    bool freq[26] = { false };
    for (int i = 0; i < s.length(); i++)
    {
        if (freq[s[i] - 'a'] == true) {
            return false;
        } else {
            freq[s[i] - 'a'] = true;
        }
    }
    return true;
}
int main() {
    string s = "machine";
    cout << isogramOrNot(s);
    return 0;
}