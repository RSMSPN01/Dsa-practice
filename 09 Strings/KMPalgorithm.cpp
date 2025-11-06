// please look video of code story with mik for the better understanding 
#include <iostream>
using namespace std;
void buildLps(int* lps, string pat) {
    lps[0] = 0;
    int i = 1, length = 0;
    while (i < pat.length())
    {
        if (pat[i] == pat[length])
        {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0)
            {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}
void findPattern(string txt, string pat) {
    int n = txt.length();
    int m = pat.length();
    int LPS[m] = { 0 };
    buildLps(LPS, pat);
    int i = 0, j = 0;
    while (i < n)
    {
        if (txt[i] == pat[j])
        {
            i++;
            j++;
        } else {
            if (j != 0)
            {
                j = LPS[j - 1];
            } else {
                i++;
            }
        }
        if (j == m)
        {
            cout << "Pattern Found at : " << i - j << endl;
            j = LPS[j - 1];
        }
    }
}
int main() {
    string txt = "geeksforgeeksandcharm";
    string pat = "eeks";
    findPattern(txt, pat);
    return 0;
}