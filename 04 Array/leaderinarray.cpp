#include <iostream>
#include <vector>
using namespace std;
void leaderArray(int arr[], int n) {
    vector <int>v;
    int max = arr[n - 1];
    v.push_back(max);
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            v.push_back(arr[i]);
        }
    }
    for (auto&& i : v)
    {
        cout << i << " ";
    }


}
int main() {
    int n = 7;
    int arr[n] = { 7,10,4,12,6,5,2 };
    leaderArray(arr, n);
    return 0;
}