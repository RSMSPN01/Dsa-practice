// permutations of each other or not 
// check if all the elements of one string exists in the other string or not
#include <iostream>
using namespace std;
bool anagram(string& str1, string& str2) {
    int freq[256] = { 0 };
    for (int i = 0; i < str1.length(); i++)
    {
        freq[str1[i]]++;
    }
    for (int i = 0; i < str2.length(); i++)
    {
        freq[str2[i]]--;
        if (freq[str2[i]] < 0)
        {
            return false;
        }
    }
    return true;
}
int main() {
    string str1 = "aabbcsc";
    string str2 = "bacabcs";
    cout << anagram(str1, str2);
    return 0;
}