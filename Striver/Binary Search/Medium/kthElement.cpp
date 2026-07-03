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

#include <bits/stdc++.h>
#include <iostream>

using namespace std;
int kthElement(vector<int> &nums1, vector<int> &nums2, int k) {
  int n1 = nums1.size(), n2 = nums2.size();
  if (n2 < n1) {
    return kthElement(nums2, nums1, k);
  }
  int leftSide = k; // this time we need k elements to the left
  bool isEven = false;
  ((n1 + n2) % 2 == 0) ? isEven = true : isEven = false;
  int l1 = 0, l2 = 0, r1 = 0, r2 = 0;
  // the ranges are modified so that mid always point at a valid index
  int low = max(0, k - n2);
  int high = min(n1, k);
  int mid1 = 0, mid2 = 0;
  while (low <= high) {
    mid1 = low + (high - low) / 2;
    mid2 = leftSide - mid1;
    (mid1 == 0) ? l1 = INT_MIN : l1 = nums1[mid1 - 1];
    (mid2 == 0) ? l2 = INT_MIN : l2 = nums2[mid2 - 1];
    (mid1 == n1) ? r1 = INT_MAX : r1 = nums1[mid1];
    (mid2 == n2) ? r2 = INT_MAX : r2 = nums2[mid2];

    if (l1 <= r2 && l2 <= r1) {
      return (max(l1, l2));
    } else if (l1 > r2) {
      high = mid1 - 1;
    } else {
      low = mid1 + 1;
    }
  }
  return 0;
}
int main() {
  vector<int> a = {2, 3, 6, 7, 9};
  vector<int> b = {1, 4, 8, 10};
  int k = 5;
  cout << kthElement(a, b, k) << endl;
  return 0;
}
