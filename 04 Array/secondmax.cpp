#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int secondMax(vector<int>& v) {
    int n = v.size();
    int max = v[0];
    int secMax = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < v[i])
        {
            secMax = max;
            max = v[i];
        }
        if (v[i] > secMax && v[i] < max)
        {
            secMax = v[i];
        }
    }
    if (secMax == INT_MIN)
    {
        return 0;
    } else {
        return secMax;
    }


}
int main() {
    vector<int>v = { 23,43,56,99,88,109 };
    int result = secondMax(v);
    if (result)
    {
        cout << "Second Max is : " << result;
    } else {
        cout << "All the elements are same";
    }


    return 0;
}