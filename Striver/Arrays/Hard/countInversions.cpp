// Naive Approach : Use two for loops and check if at any point arr[i] > arr[j],
// increment the total count and in the end return it
// T.C = O(n^2) and S.C = (1)

// Better Appraoch : using merge sort, so the intiution behind this is we have
// to count how many swapping of numbers are required to make the array again in
// sorted order. So we can use a specific formula while merging the two sorted
// arrays and can count the inversions i am not be able to think of the formula
// which i can use to find the inversion but i know this is how we are going to
// do this question
// T.C = O(nlogn) and S.C = (1)

#include <algorithm>
#include <iostream>
#include <vector>

int inversion = 0;
using namespace std;
void merge(vector<int> &nums, int low, int high) {
  int mid = (low + high) / 2;
  int i = low, j = mid + 1;
  int k = 0, n = high - low + 1;
  int temp[n] = {0};
  while (i <= mid && j <= high) {
    if (nums[i] <= nums[j]) {
      temp[k] = nums[i];
      i++;
    } else {
      temp[k] = nums[j];
      j++;
      // the formula to be used here
      inversion += mid - low + 1;
    }
    k++;
  }
  while (i <= mid) {
    temp[k] = nums[i];
    i++;
    k++;
  }
  while (j <= high) {
    temp[k] = nums[j];
    j++;
    k++;
  }
  for (int i = 0; i < n; i++) {
    nums[i + low] = temp[i];
  }
}

void mergeSort(vector<int> &nums, int low, int high) {
  int mid = (low + high) / 2;
  if (low < high) {
    mergeSort(nums, low, mid);
    mergeSort(nums, mid + 1, high);
    merge(nums, low, high);
  }
}

long long int numberOfInversions(vector<int> nums) {
  int low = 0, high = nums.size() - 1;
  mergeSort(nums, low, high);
  return inversion;

  // Naive approach
  //   int n = nums.size();
  //   int count = 0;
  //   for (int i = 0; i < n - 1; i++) {
  //     for (int j = i + 1; j < n; j++) {
  //       if (nums[i] > nums[j]) {
  //         count++;
  //       }
  //     }
  //   }
  //   return count;
  return 0;
}
int main() {
  vector<int> nums = {9, 5, 4, 2};
  cout << numberOfInversions(nums);
  cout << endl;

  return 0;
}