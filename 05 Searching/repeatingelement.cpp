#include <iostream>
using namespace std;
int repeatingElement(int arr[]) {
    // this code is for inplace repeating element check
    // int i = 0;
    // while (i < n)
    // {
    //     if (arr[i] < 0)
    //     {
    //         i++;
    //     } else {
    //         if (arr[arr[i]] >= 0)
    //         {
    //             int index = arr[i];
    //             arr[i] = arr[index];
    //             arr[index] = -1;
    //         } else {
    //             return arr[i];
    //         }
    //     }
    // }
    // return -1;

    // Floyd's Cycle Detection
    int fast = 0;
    int slow = 0;
    fast = arr[arr[fast] + 1] + 1;
    slow = arr[slow] + 1;
    while (fast != slow)
    {
        fast = arr[arr[fast] + 1] + 1;
        slow = arr[slow] + 1;
    }
    int point = 0;
    while (point != slow)
    {
        point = arr[point] + 1;
        slow = arr[slow] + 1;
    }
    return point - 1;
    // the reason of adding one to each is there exists a zero in the element which 
    // don't follow the case of FCD that is why we are adding one to change the values
    // each value is treated as +1 and if no zero exists then don't add one.
}
int main() {
    int n = 8;
    int arr[n] = { 0,3,2,1,6,3,4,5 };
    // the value is the arr[n] <=n-2
    // there must exist atleast one repeating value in the array.
    // i will use the index of the array to store the elements in the array.
    cout << repeatingElement(arr);
    return 0;
}