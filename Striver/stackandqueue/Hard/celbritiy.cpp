// Naive Approach : So go to each person and see is he known by everybody and
// should not know anybody if we found one return directly but the T.C= O(n^2)

// Better Approach : I know he is celebrity and he should be known by all other
// peoples so i go only to peoples one by one and see who is known the most,
// when found one then we will go and check if that guy doesn't know anybody
// else but the worst case will be O(n^2) in this but is better then above

// just a little refinement in this approach
// We need two extra arrays two store how many people knows x person and how
// much person x is known by people and if we found at any case that a person
// knows zero person and know by n - 1 people that is it.

// So There could be possibly only one celebrity,not more then that is possible
// First lets see how to to solve this optimaly using two pointer approach
// How do i come up with the two pointer appraoch i don't realy know that, how
// this is even used here is mind bogling as well.

// Now this question is marked as stack and queue but how to use it idk at all
// let seek some help and come back to solve this
// So with stack it is little differnt and unnecessary to do that way, first put
// elements inside the stack and then see wheter they know each other or not if
// anyone of them know each other just pop that out in the end you will left
// with the celebrity

#include <bits/stdc++.h>
#include <iostream>

using namespace std;
int celebrity(vector<vector<int>> &M) {
  // So we know for sure that the celibrity must known by somebody
  // and we took advantage of that thing
  // using two pointer here
  int top = 0, bottom = M.size() - 1;
  while (top < bottom) {
    if (M[top][bottom] == 1) {
      // it means top knows somebody and a celeb can't know
      // someone, so this is sure this can't be my ans
      top++;
    } else if (M[bottom][top] == 1) {
      // bottom knows somebody can't be my ans
      bottom--;
    } else {
      // if both don't know each other then both can't be celeb
      // bcs celeb must be known by somebody
      top++;
      bottom--;
    }
  }
  if (top > bottom) {
    // means there is no such celebrity
    return -1;
  } else {
    // check for the entire row and column maybe he could be a celeb
    for (int i = 0; i < M.size(); i++) {
      if (i == top) {
        continue;
        // don't check the diagonal element
      }
      if (M[top][i] != 0 || M[i][bottom] != 1) {
        return -1;
      }
    }
  }
  // return the last pointer where it is pointing to
  return top;
}
int main() {
  vector<vector<int>> v = {
      {0, 1, 1, 0}, {0, 0, 0, 0}, {1, 1, 0, 0}, {0, 1, 1, 0}};
  cout << celebrity(v);

  return 0;
}