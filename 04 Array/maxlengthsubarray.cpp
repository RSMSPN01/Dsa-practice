#include <iostream>
using namespace std;
int maxlengthsubarray(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n;)
    {
        if ((arr[i]&1)&&(arr[i+1]&1)==0)
        {
            
        }
        
    }
    
}
int main() {
    int n = 6;
    int arr[n] = { 2,4,8,7,6,5 };
    int res = maxlengthsubarray(arr, n);
    cout << res;
    return 0;
}