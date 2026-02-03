// Naive Approach : Traverse the whole matrix step by step and count the max
// value of each row and return the row with max values
// T.C = O(row * col (n^2)) and S.C = O(1)

// Better Appraoch : We know we have sorted array so we can apply bs on this and
// by going to each row one by one count the occurences of 1
// T.C = (row*log(col)) and S.C = O(1)

// Optimal Approach : We can use the simple observation here that we use in
// sorted matrix starting from the top right and keep checking and storing the
// result for the minimum T.C = O(row + col) and S.c = O(1) i am not going to
// write that code, look the next same problem on leetcode you will find the
// similar code there
//
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
// this function helps in to count the number of one's in a row
int countOnes(vector<vector<int>> &mat, int row, int col) {
  int low = 1, high = col - 1, mid = 0;
  // we don't have to think about edge cases those are already covered in the
  // loop below down there
  while (low <= high) {
    mid = low + (high - low) / 2;
    if (mat[row][mid] == 1 && mat[row][mid - 1] != 1) {
      return col - mid;
    } else if (mat[row][mid] == 1) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return 0;
}
int rowWithMax1s(vector<vector<int>> &mat) {
  int row = mat.size(), col = mat[0].size();
  int rowMax = -1, prevMaxCount = 0;
  for (int i = 0; i < row; i++) {
    int count = 0;
    // handle edge cases before even going ahead
    if (mat[i][0] == 1) {
      // it means first element of the row is already one then return
      return i;
    }
    if (mat[i][col - 1] == 1) {
      // check even if there exist one in the row or not if exists
      // then only go and check the row.
      count = countOnes(mat, i, col);
      if (count > prevMaxCount) {
        prevMaxCount = count;
        rowMax = i;
      }
    } else {
      continue;
    }
  }
  return rowMax;
}

int main() {
  vector<vector<int>> nums = {{0, 0, 1}, {0, 1, 1}, {1, 1, 1}};
  cout << rowWithMax1s(nums);
  return 0;
}