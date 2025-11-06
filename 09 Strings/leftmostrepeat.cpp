#include <iostream>
using namespace std;
int leftMostRepeating(string& str) {
    bool freq[256] = { false };
    int result = 0;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (freq[str[i]])
        {
            result = i;
        } else {
            freq[str[i]] = true;
        }
    }
    return result;
}
int main() {
    string str = "abbcc";
    cout << leftMostRepeating(str);
    return 0;
}