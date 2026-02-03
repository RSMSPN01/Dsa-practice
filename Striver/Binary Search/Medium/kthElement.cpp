// Naive Approach : We can use two pointers and sort the array in O(n) time and
// with space O(n), we need to further optimize this by the fact that both the
// arrays are in sorted order

// Better Approach : We can also solve this using two pointers by placing the
// pointers at the start then compare one by one and take another variable as
// count if count == k then return the pointer which is pointing to the current
// index
// Time C = O(n + m), Space C = O(1)

// Optimal Approach : I think we are going to use bs in this but don't know how
// lets try to think (nah not able to think any idea man) lets see video
// i will come back to solve the question, it is same as the median question
// but how low and high is selected is a kind of odd for me so i will skip this
// for now comebackk later on.
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int kthElement(vector<int> &a, vector<int> &b, int k) {}
int main() {
  vector<int> a = {2, 3, 6, 7, 9};
  vector<int> b = {1, 4, 8, 10};
  int k = 5;
  cout << kthElement(a, b, k);
  return 0;
}
