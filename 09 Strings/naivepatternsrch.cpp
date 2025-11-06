#include <iostream>
using namespace std;
void naiveSearch(string& str1, string& str2) {
    for (int i = 0; i < str1.length() - str2.length() + 1; i++)
    {
        if (str1[i] == str2[0]) {
            int index = i + 1, flag = 1, noob = i;
            for (int j = 1; j < str2.length(); j++)
            {
                if (str1[index++] != str2[j])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                cout << noob << " ";
            }
        }
    }
}
// size_t pos = str1.find(str2);
// while (pos != string::npos) {
//     cout << pos << " ";
//     pos = str1.find(str2, pos + 1);
// }
int main() {
    string str1 = "AAAAA";
    string str2 = "AAA";
    naiveSearch(str1, str2);
    return 0;
}