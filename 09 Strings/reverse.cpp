#include <iostream>
using namespace std;
void reverseStr(string& str, int start, int end) {
    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}
int main() {
    string str = "Please Reverse Me";
    int i = 0, j = 0;
    while (str[j] != '\0')
    {
        if (str[j] == ' ')
        {
            reverseStr(str, i, j - 1);
            i = j + 1;
        }
        j++;
    }
    reverseStr(str, i, str.length() - 1);
    reverseStr(str, 0, str.length() - 1);
    cout << str;
    return 0;
}