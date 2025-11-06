#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maximumGuests(int ari[], int dep[], int n) {
    // so rather than looking it as an interval problem we solve the problem as 
    // merging two arrays problem by looking how many guests are present at the current time together
    
    sort(dep, dep + n);
    int i = 1, j = 0, guests = 1, maxi = 1;
    while (i < n && j < n)
    {
        if (ari[i] < dep[j])
        {
            guests++;
            i++;
        } else {
            guests--;
            j++;
        }
        maxi = max(maxi, guests);
    }
    return maxi;
}
int main() {
    int n = 4;
    int ari[n] = { 500,700,600,800 };
    int dep[n] = { 530,830,820,840 };
    cout << maximumGuests(ari, dep, n);
    return 0;
}