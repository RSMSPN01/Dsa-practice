#include <iostream>
using namespace std;
void countFrequency(int arr[], int n) {
    // please note that the size of the array in not going to be less then 2;
    int currenElement = arr[0];
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == currenElement)
        {
            count++;
        } else {
            cout << currenElement << " " << count << endl;
            currenElement = arr[i];
            count = 1;
        }

    }
    cout << currenElement << " " << count << endl;
}
int main() {
    int n = 8;
    int arr[n] = { 10,10,10,25,30,30,30,31 };
    countFrequency(arr, n);
    return 0;
}