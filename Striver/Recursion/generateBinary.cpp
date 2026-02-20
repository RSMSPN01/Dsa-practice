// Niave Approach : we know for each test case (0,1,2) are valid cases so will
// start from the number 3 and go till 2^n by checking for each number if they
// have consecutive bits or not, if they have then store it.
// But the time complexity is very high even with recursion the call stack is
// going to be 2^n there must be some formula to find directly

// there is no formula but its a pattern question (new for me) lets study

#include <bitset>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
// Tips : So what i am thinking right now to generate a pattern for the first
// time i know that we need to call the function twice to make it possible i
// need to check the last value if its zero then add 1 and vice versa base
// condtion i know if it reaches zero or become n but don't know how to combine
// these all together
// even after all that i have to saw the code and i get some idea about its
// working

using namespace std;
// efficient way to do this question
void returnString(int n, string curr, vector<string> &result) {
  // base case
  if (curr.length() == n) {
    result.push_back(curr);
    return;
  }
  // always add zero
  returnString(n, curr + "0", result);
  // only add when last value in string is not 1 and if it is empty.
  if (curr.empty() || curr.back() != '1') {
    returnString(n, curr + '1', result);
  }
}
vector<string> generateBinaryStrings(int n) {
  // This was niave way and even we have to write seprate code for converting
  // numbers into binary form so its not a valid thing to do.
  vector<string> result;
  if (n == 1) {
    return {"0", "1"};
  }
  if (n >= 2) {
    result.push_back("0"); // push them in but there bit values
    result.push_back("1");
    result.push_back("2");
    for (int i = 3; i < pow(2, n); i++) {
      if (i & (i >> 1)) {
        continue;
      } else {
        // int temp = bitset<n>(i);
        // result.push_back(to_string(temp));
        // push it in for later
        // just for checking
        result.push_back(to_string(i));
      }
    }
  }
  return result;
}
int main() {
  // naive function
  // vector<string> x = generateBinaryStrings(3);
  // for (auto &&i : x) {
  //   cout << i << " ";
  // }
  vector<string> result;
  int n = 3;
  // efficient way
  returnString(n, "", result);
  for (auto &&i : result) {
    cout << i << " ";
  }
  return 0;
}