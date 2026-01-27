// Naive appraoch : Breaking the question in two steps in first we will find out
// the repeating number and in the second step finding the missing number
// two loops for each of the steps using sorting the vector at the first hand we
// can do that easily T.C = O(nlogn) + S.C = O(1)

// Better Approach : We can solve this problem without sorting by considering
// the fact that we have values from 1 to n and when we have given something
// like this then we can use the indexes itself to solve the problem, i am going
// to use two loops in which first i find the repeating number and then i will
// find the missing number and turning the array back to its original elements
// T.C = O(n + n) and S.C = O(1)

// Optimal Approach : Using traversal only one single time (from striver)
//  either by maths (solving equations) or using bit manipulation
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
vector<int> findMissingRepeatingNumbers(vector<int> &nums) {
  // we can also simply create the copy of the original vector instead of
  // sending the reference this will save one more step in which we have to
  // again make the vector same as it was earlier

  // step 1 : find the repeating
  // element approach : mark the seen index as negative and store the value
  // int repeatEle = 0;
  // for (int i = 0; i < nums.size(); i++) {
  //   int index = abs(nums[i]) - 1;
  //   if (nums[index] < 0) {
  //     // it means we are marking this element for the second time
  //     repeatEle = index + 1;
  //   } else {
  //     // keep on marking the indexes
  //     nums[index] = -nums[index];
  //   }
  // }
  // int missEle = 0;
  // for (int i = 0; i < nums.size(); i++) {
  //   if (nums[i] > 0) {
  //     // anyone which is not marked, means it is the missing value
  //     missEle = i + 1;
  //   } else {
  //     // turn the array back to original position
  //     nums[i] = abs(nums[i]);
  //   }
  // }
  // return {repeatEle, missEle};

  // striver optimal method
  // using bit manipulation
  // Approach : if we do xor of all the values in nums and we know that values
  // are from 1 to n so we do xor from 1 to n all the values will get canceled
  // out except for the two numbers one which is repeating and other one which
  // is missing in this case the final xor is of (4 ^ 7) you can even dry run
  // and check that and once we have the two values now we can do the same thing
  // which we do in the question of finding two odd one out in the array

  // spliting the array into two parts and getting the two xor value back
  // dry run the code for understanding why we also did xor of i in last loop
  // T.C = O(n + setBit + n + n)  S.C = O(1)

  int n = nums.size();
  int ans = 0;

  for (int i = 0; i < n; i++) {
    // in single loop we can calculate both the Xor all the elements of array
    // and from 1 to n numbers as well
    ans ^= nums[i];
    ans ^= i + 1;
  }
  int setBit = 0;
  //  now check which bit is set so based on that we can divide the array
  // there is a trick to directly get the bit mask we don't need to explicitly
  // check again and again
  setBit = ans & ~(ans - 1);
  // while (ans > 0) {
  //   if (ans & 1) {
  //     break;
  //   } else {
  //     setBit++;
  //     ans >>= ans;
  //   }
  // }

  int firstEle = 0;
  int scndEle = 0;
  for (int i = 0; i < n; i++) {
    if (nums[i] & setBit) {
      firstEle ^= nums[i];
    } else {
      scndEle ^= nums[i];
    }
    // this is one more extra step bcs when we also do xor from 1 to n
    // the same numbers will get canceled out with each other and final result
    // will be there.
    if (i + 1 & setBit) {
      firstEle ^= i + 1;
    } else {
      scndEle ^= i + 1;
    }
  }
  // before returning it we also need to run a loop again which will check which
  // of these two numbers are actually missing and repeating and then return
  // based on that loop iterations
  return {firstEle, scndEle};
}
int main() {
  vector<int> nums = {1, 2, 3, 6, 7, 5, 7};
  vector<int> x = findMissingRepeatingNumbers(nums);
  // the original vector values should be same after the calculation

  // for (auto &&i : nums) {
  //   cout << i << " ";
  // }

  for (auto &&i : x) {
    cout << i << " ";
  }

  return 0;
}