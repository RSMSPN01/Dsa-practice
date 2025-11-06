#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int randomIndex(int low, int high) {
    srand(time(0)); // Seed the random generator with current time
    // because machines can't generate random numbers they input the current time
    // based on that they seed them and come up with an random number from the time
    // because time is always different
    int randomNum = low + rand() % (high - low + 1);
    return randomNum;
}
int hoarePartition(int arr[], int low, int high) {
    int i = low - 1, j = high + 1, pivot = arr[low];
    while (true)
    {
        do
        {
            i++;
        }
        while (arr[i] < pivot);
        do
        {
            j--;
        }
        while (arr[j] > pivot);
        if (i >= j)
        {
            return j;
        }
        swap(arr[i], arr[j]);
    }
}
void quickSort(int arr[], int l, int h) {
    while (l < h)
    {
        int r = randomIndex(l, h);
        swap(arr[l], arr[r]);
        int p = hoarePartition(arr, l, h);
        quickSort(arr, l, p);
        l = p + 1; // remove this tail recursion to better optimize it but i can't dry run that program
        // although the compiler can automatically handles the tail recursions by itself behing the scenes
        //  but it is still a better practice to write it by yourself rather not rely on the compiler for the tail recursion.
    }
}
int main() {
    int n = 7;
    int arr[n] = { 8,4,7,9,3,10,5 };
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
