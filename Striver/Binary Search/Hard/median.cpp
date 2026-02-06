// Niave Approach : Flatten the array into sorted 1D array and then find out the
// midean T.C = (m*n + NlogN) and S.C = O(N)

// Better Approach : I try to think but i am not be able to think of any better
// solution then the niave way.
// Lets see what others have done
// So we will the apply binary search directly on the range of numbers and check
// if that could be our possible median or not

// The code i have written works fine when there are no duplicates in the matrix
// but if duplicates are there then whole logic of the code just breaks bcs if
// we have eg array - 1,3,3,3,3,3,3 now this is of 7 length and i wil check oh i
// need 4 in left and 3 in right but when mid is 3 it will count all values <=3
// to the left side and which make 3 as a wrong answer but it is the valid
// median. so I don't really know how to fix this thing lets watch video now.

// Here almost everthing which i did is right but instead of directly returning
// the answer we need to find out the upper bound instead of direct return and
// in the end low will be pointing to the final answer

// To be a valid median the count of the number should be greater than or equal
// to the row*col/2 times instead of finding left

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int countSmaller(vector<vector<int>> &matrix, int value) {
  // function return the count of elements i.e. matrix[i][j] <= value
  int n = matrix.size(), m = matrix[0].size();
  int count = 0;
  for (int i = 0; i < n; i++) {
    int low = 0, high = m - 1, mid = 0;
    while (low <= high) {
      mid = low + (high - low) / 2;
      if (matrix[i][mid] > value) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    count += high + 1;
  }
  return count;
}
int findMedian(vector<vector<int>> &matrix) {
  // Step 1 : First find out the range from where to apply bs from
  // i.e max and min number in the array.
  int n = matrix.size(), m = matrix[0].size();
  int total = m * n;
  int low = INT_MAX, high = 0;
  for (int i = 0; i < n; i++) {
    low = min(low, matrix[i][0]);
    high = max(high, matrix[i][m - 1]);
  }
  // Step 2 : now apply binary search on the range
  int mid = 0;
  while (low <= high) {
    mid = low + (high - low) / 2;
    // now count how many elemnets are in the array lesser then mid value
    int count = countSmaller(matrix, mid);
    // if (count == (total / 2) + 1) {
    //   // left side have n/2+1 elements, so we have got the value
    //   return mid;
    // }
    if (count > total / 2) {
      // reduce the search space
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  // we need to return the upper bound
  return low;
}
int main() {
  vector<vector<int>> nums = {{1, 4, 9}, {2, 5, 6}, {3, 7, 8}};
  cout << findMedian(nums);
  return 0;
}