#include <iostream>
#include <vector>
#include <climits>
using namespace std;
void maxOccurance(int start[], int end[], int n) {
    vector<int>freq(11, 0); // given in question that it will not exceed the range of 1000
    for (int i = 0; i < n; i++)
    {
        freq[start[i]]++;
        freq[end[i] + 1]--;
    }
    int currSum = 0;
    for (int i = 0; i < 11; i++)
    {
        currSum += freq[i];
        freq[i] = currSum;
    }
    int max = INT_MIN;
    int index = -1;
    for (int i = 0; i < 11; i++)
    {
        cout << freq[i] << " ";
        // if (freq[i] > max)
        // {
        //     max = freq[i];
        //     index = i;
        // }
    }
    // cout << "Maximum Occuring Element is : " << index;
}
int main() {
    int n = 3;
    int arr1[n] = { 2,4,5 };
    int arr2[n] = { 5,8,9 };
    maxOccurance(arr1, arr2, n);
    return 0;
}