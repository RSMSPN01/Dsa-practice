#include <iostream>
using namespace std;
int maxProfit(int price[], int n) {
    // if array size is one then return 0 ;
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        if (price[i] > price[i - 1])
        {
            profit += price[i] - price[i - 1];
        }
    }
    return profit;

}
int main() {
    int n = 5;
    int arr[n] = { 1,5,3,8,12 };
    int profit = maxProfit(arr, n);
    cout << profit;
    return 0;
}