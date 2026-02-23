// Approach : So we have this basic template for any code
// take it or not take it
// basic subsequence printing template

// if (i == v.size()) {
//   return 0;
// }
// include it first
// add.result[i];
// again call function fun(i+1)
// remove.result[i]
// again call function fun(i+1)

#include <iostream>
#include <vector>
using namespace std;

int printSubSeq(vector<int> &v, int i, int sum, int target) {
  // base case
  if (sum == target) {
    return 1;
  }
  if (sum > target || i == v.size()) {
    return 0;
  }
  // here first we are including and then next we are not
  // including 
  return printSubSeq(v, i + 1, sum + v[i], target) + printSubSeq(v, i + 1, sum, target);
}
int main() {
  vector<int> v = {1, 2, 3, 4};
  int target = 6;
  cout << printSubSeq(v, 0, 0, target);
  return 0;
}