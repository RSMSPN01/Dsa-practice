#include <iostream>
using namespace std;
void cycleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
    {
        int item = arr[i];
        int pos = i;
        for (int cs = i + 1; cs < n; cs++)
        {
            if (arr[cs] < item)
            {
                pos++;
            }
        }
        swap(item, arr[pos]);
        while (i != pos)
        {
            pos = i;
            for (int cs = i + 1; cs < n; cs++)
            {
                if (arr[cs] < item)
                {
                    pos++;
                }
            }
            while (item == arr[pos])
            {
                pos++;
            }
            swap(item, arr[pos]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main() {
    int n = 5;
    int arr[n] = { 3,2,1,2,3 };
    cycleSort(arr, n);
    return 0;
}