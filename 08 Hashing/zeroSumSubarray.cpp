#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int arr[5] = { -3,4,-3,1,1 };
    unordered_set<int>s;
    int preSum = 0;
    for (int i = 0; i < 5; i++)
    {
        preSum += arr[i];
        if (s.find(preSum) != s.end())
        {
            cout << "It is present my friend" << endl;
            break;
        }
        if (preSum == 0) // to handle the edge cases like [-3,2,1,4] so directly check if it becomes zero then just simply return that.
        {
            cout << "It is present my friend" << endl;
            break;
        }

        s.insert(preSum);
    }
    return 0;
}