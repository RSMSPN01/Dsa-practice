// Naive Approach : Maintain K size window, which we simultaneously count the
// frequency and return the count of the values.
// T.C= O(n^3) S.C = O(n) most brute force out there it can be improved though
// By using backtracking in the question
#include <iostream>
#include <string>
using namespace std;

int distinctElements(string &s) {
  int n = s.length();
  int freq[26] = {0};
  int count = 0;
  for (int i = 0; i < n; i++) {
    freq[s[i] - 'a']++;
  }

  for (int i = 0; i < 26; i++) {
    if (freq[i] > 0) {
      count++;
    }
  }
  return count;
}
int kDistinctictSubString(string &s, int k) {
  int n = s.length();
  int temp = k;
  int count = 0;
  // unordered_set < string > freq;
  while (k <= n) {
    for (int i = 0; i < n - k + 1; i++) {
      int j = k + i;
      string result = s.substr(i, k);
      if (distinctElements(result) == temp) {
        count++;
      }
    }
    k++;
  }
  return count;
}
int main() {
  string s = "pqpqs";
  cout << kDistinctictSubString(s, 2);
  return 0;
}