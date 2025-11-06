#include <iostream>
using namespace std;
void plusOne(int* arr, int n) {
    if (arr[n - 1] < 9)
    {
        arr[n - 1] = arr[n - 1] + 1;
        return;
    } else {
        int carry = 1;
        for (int i = n - 1; i >= 0, carry != 0;i--)
        {
            int num = carry + arr[i];
            arr[i] = num % 10;
            carry = num / 10;
        }
        if (carry) // if carry is still one then i have to create an another array and return that
        {
            
        }
        return;
    }
}
int main() {
    int n = 3;
    int arr1[n] = { 1,2,3 };
    int arr2[n] = { 1,2,9 };
    int arr3[n] = { 9,9,9 };
    // plusOne(arr2, n);
    // for (auto&& i : arr2)
    // {
    //     cout << i << " ";
    // }

    return 0;
}