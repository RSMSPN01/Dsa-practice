#include <iostream>
#include <vector>
using namespace std;
// There is already a way to find all the factors of the number but the question is different because of the TC it will give it works in 
// O(log n) time compared to O(sqrt(n)) for other methods although a prerequisits array is required to compute the results this faster
// which gives us the SC = O(n) and we should use this approach if we have given n number of queries and we need to find the factors of it.
// try to understand the question by yourself and from notes as well if still not able to understand this then try watching the striver video.
void primeFactorization(vector<int> q) {
    // step 1: make the factor array in which the data is already stored before hand.
    // let just suppose we are working only with the numbers less then 100 right now else we have to create the array of size 10^5 or even more
    vector<int> factor(100);
    for (int i = 2; i < 100; i++)
    {
        factor[i] = i; // fill the vector with the count of the numbers itself
    }
    for (int i = 2; i * i <= 100; i++) // run this loop till sqrt because all the multiple of i is covered in the second loop.
    {
        if (factor[i] == i) // it means it is the smallest and it is the prime number
        {
            //now make all the factors of this i equals to the smallest prime number which is i here
            for (int j = i * i; j < 100; j = j + i)
            {
                if (factor[j] == j) // to prevent the collision of numbers which have more than one multiples eg: 6 is divided by 2 and 3 so
                { // when the loop comes to 3 it will overwrite it to 3 but the smallest prime for 6 is 2 so to stop this we use this condition
                    factor[j] = i;
                }
            }
        }
    }
    // we have the factor array ready to use now we can directly compute the result 
    // step 2: Compute the results now and return it in the form of vector 

    for (int i = 0; i < q.size(); i++)
    {
        if (q[i] == 0 || q[i] == 1) {
            cout << 0 << " ";
        }
        int temp = q[i]; // store the value in the temp
        while (temp != 1)
        {
            cout << factor[temp] << " "; // print the prime number or the factor of it
            temp = temp / factor[temp]; // update the value of temp until it becomes one because in the end it will become one.
        }
    }
}
int main() {
    vector<int>q = { 2,3,4,5,6 };
    primeFactorization(q);
    return 0;
}