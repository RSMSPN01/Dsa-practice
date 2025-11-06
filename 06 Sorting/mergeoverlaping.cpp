#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    vector<vector<int>>arr = { {1,3},{2,4},{5,7},{6,8} };
    vector<vector<int>>res;
    sort(arr.begin(), arr.end());
    int n = arr.size();
    res.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (arr[i][0] < res.back()[1])
        {
            res.back()[1] = max(res.back()[1], arr[i][1]);
        } else {
            res.push_back(arr[i]);
        }
    }
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i][0] << "," << res[i][1] << " ";
    }



    // int n = 2;
    // int arr[][n] = { {1,3},{2,4},{5,7},{6,8} };
    // // sort(arr.begin(), arr.end());
    // int res = 0;
    // for (int i = 1; i < 4; i++)
    // {
    //     if (arr[res][1] > arr[i][0])
    //     {
    //         arr[res][1] = max(arr[res][1], arr[i][1]);
    //     } else {
    //         res++;
    //         arr[res][0] = arr[i][0];
    //         arr[res][1] = arr[i][1];
    //     }
    // }
    // for (int i = 0; i <= res; i++)
    // {
    //     cout << arr[i][0] << "," << arr[i][1] << " ";
    // }


    return 0;
}