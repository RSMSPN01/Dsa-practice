// This is the anagram pattern searching but the pattern could be the permutation of the actual string
// Total complexity is O(n);
#define CHAR 256
#include <iostream>
using namespace std;
bool isSame(int arr1[], int arr2[]) {
    for (int i = 0; i < CHAR; i++)
    {
        if (arr2[i] != arr1[i])
        {
            return false;
        }
    }
    return true;
}
bool anagram(string& txt, string& pat) {
    int freqTxt[CHAR] = { 0 };
    int freqPat[CHAR] = { 0 };
    for (int i = 0; i < pat.length(); i++)
    {
        freqTxt[txt[i]]++; // count the frequency which will take linear time.
        freqPat[pat[i]]++;
    }
    for (int i = pat.length(); i < txt.length(); i++) // this loop will again take linear time.
    {
        if (isSame(freqPat, freqTxt))
        {
            return true;
        }
        freqTxt[txt[i]]++; // this is rolling function which is constant in time 
        freqTxt[txt[i - pat.length()]]--; // simply remove last and add new one;
    }
    return false;
}
int main() {
    string txt = "geekforgeeks";
    string pat = "frog";
    cout << (anagram(txt, pat) ? "True" : "False");
    return 0;
}