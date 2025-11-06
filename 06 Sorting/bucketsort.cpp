#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void bucketSort(int arr[], int n, int k) {
    int maximum = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maximum)
        {
            maximum = arr[i];
        }
    }
    maximum += 1;
    vector<int>bkt[k]; // rows are fixed but columns are not fixed.
    for (int i = 0; i < n; i++)
    {
        int in = k * arr[i] / maximum; // dividing the elements in each bucket
        bkt[in].push_back(arr[i]);
    }
    for (int i = 0; i < k; i++)
    {
        sort(bkt[i].begin(), bkt[i].end());
    }
    // now again combine the results
    int index = 0;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < bkt[i].size(); j++)
        {
            arr[index++] = bkt[i][j];
        }
    }
}
int main() {
    int n = 9, k = 5;
    int arr[n] = { 20,88,70,85,75,95,18,82,60 };
    bucketSort(arr, n, k);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}