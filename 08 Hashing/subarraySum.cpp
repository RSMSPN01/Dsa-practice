#include <iostream>
#include <unordered_set>
using namespace std;
// please make the note for this too 
int main() {
    int arr[] = { 5,8,6,13,3,-1 };
    int k = 22;
    unordered_set<int>s;
    int preSum = 0;
    for (int i = 0; i < 6; i++)
    {
        preSum += arr[i];
        if (preSum == k) // to handle if the array is already in sorted order
        {
            cout << "Wallahi! it is present";
            break;
        }

        if (s.count(preSum - k))
        {
            cout << "Wallahi! it is present";
            break;
        }
        s.insert(preSum);
    }
    return 0;
}