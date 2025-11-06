// Check if strings are rotations of each other or not 
// make note of this 
#include <iostream>
using namespace std;
bool stringRotated(string& str1, string& str2) {
    // int n = 0;
    // if (str1.length() != str2.length())
    // {
    //     return false;
    // } else {
    //     n = str1.length();
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     if (str2[0] == str1[i])
    //     {
    //         for (int j = 0; j < n; j++)
    //         {
    //             if (str2[j] != str1[(i + j) % n])
    //             {
    //                 return false;
    //             }
    //         }
    //     }
    // }
    // return true;
    return (str1.length() == str2.length() && (str1 + str1).find(str2) != string::npos);
    // works on this intiution that str2 must be a substring of str1+str1 so this is the logic we are using here

}
int main() {
    string str1 = "mightandmagic";
    string str2 = "ndmagicmighta";
    cout << (stringRotated(str1, str2) ? "True" : "False");
    return 0;
}