// Approach : Brute force : We need to find the minimum time to complete the paint
// So we will run a loop which will start from 0 and keep on moving till the very
// last part and whenever it gets a true value it will return the ith index 

// Better Approach : Use BS here, it is same question of pattern max of min i guess,
// So will use the same approach for solving the previous question, just a little 
// changes is made in the valid function 

// search Space : low will start from the max, in the array not just the direct max
// but the total time max and goes till the maximum time possible.// look for code 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool paintInTime(int time, int A, int B, vector<int>& C) {
    // I have multiply B here in almost every line, bcs i need to check it 
    // with the real time possible to paint the ith board,
    // time is seprately given in B and length of board is given in C 
    // so get total time i multiply B and C, i hope you get that.

    int paintersRequired = 0;
    int validTime = 0;
    for (int i = 0; i < C.size(); i++)
    {
        if (validTime + C[i] * B <= time) {
            validTime += (C[i] * B);
        } else {
            // reset it again.
            paintersRequired++;
            validTime = (C[i] * B);
        }
    }
    if (validTime > 0) {
        paintersRequired++;
    }
    if (paintersRequired <= A) {
        return true;
    }
    return false;
}
int paint(int A, int B, vector<int>& C) {
    // we can even modify the passed array, but we won't, instead i can make
    // a check seprately 
    int low = *max_element(C.begin(), C.end()) * B;
    // multiply with B bcs it is the actual max time to print the largest 
    // board 
    int sum = 0;
    for (int i = 0; i < C.size(); i++)
    {
        sum += C[i];
    }
    int high = sum * B; // again multiply with B to get the max time possible
    // to paint all the boards
    int mid = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (paintInTime(mid, A, B, C))
        {
            // look for even more minimum value
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}
int main() {
    vector <int> nums = { 5, 10, 30, 20 };
    int a = 3, b = 2;
    cout << paint(a, b, nums);
    return 0;
}