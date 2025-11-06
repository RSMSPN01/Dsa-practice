#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int arr[n] = { 13,54,65,89,23 };
    int max = arr[0];
    int index = 0;
    for (int i = 1; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
            index = i;
        }
    }
    cout << "Element found at Index : " << index + 1 << endl;


    return 0;
}