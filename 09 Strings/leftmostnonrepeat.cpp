#include <iostream>
using namespace std;

int main() {
    string str = "geekforgeeks";
    int freq[256] = { -1 };
    fill(freq, freq + 256, -1);
    for (int i = 0; i < str.length(); i++)
    {
        if (freq[str[i]] == -1) {
            freq[str[i]] = i;   // visting it for the first time.(store index)
        } else {
            freq[str[i]] = -2;   // visting it twice.
        }
    }
    int result = INT16_MAX;
    for (int i = 0; i < 256; i++)
    {
        if (freq[i] >= 0)
        {
            result = min(result, freq[i]);
        }
    }
    cout << result << endl;
    return 0;
}