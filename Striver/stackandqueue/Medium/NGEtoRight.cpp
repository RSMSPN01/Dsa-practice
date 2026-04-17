// Approach : Just keep the stack monotonic and keep counting its size for each
// index This way is wrong for doing this, it will miss some of the elements
// while storing the elements.

// I am not be able to think of any better approach then this, all i am thinking
// is the very brute force approach for this

// This question is actually misleading in the sheet, it actually belongs to
// tree DS once you finish that topic come back to solve this question.

#include <bits/stdc++.h>

using namespace std;
vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
  // Your code goes here
  int n = arr.size() - 1;
  stack<int> s;
  unordered_map<int, int> count;
  for (int i = n; i >= 0; i--) {
    while (!s.empty() && arr[i] >= s.top()) {
      s.pop();
    }
    // store the indexes in map not the actual value
    count[i] = s.size();
    // push the actual value not the index
    s.push(arr[i]);
  }
  vector<int> ans(indices.size());
  for (int i = 0; i < indices.size(); i++) {
    ans[i] = count[indices[i]];
  }
  return ans;
}
int main() {
  vector<int> x = {3, 4, 2, 7, 5, 8, 10, 6};
  vector<int> i = {0, 5};
  vector<int> v = count_NGE(x, i);
  for (int i : v) {
    cout << i << " ";
  }
}