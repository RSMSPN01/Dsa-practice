// Approach : It is the same approach as we to sovle the word search problem
// The code which i have written is not bad but i have written the code more
// repeatidely again and again avoid doing that, also i have changed the
// actuall input of the code, instead take a visited array and also avoid
// taking extra boolean varaible just include that in the condition itself

#include <iostream>
#include <string>
#include <vector>
using namespace std;
void helper(string &temp, vector<string> &ans, vector<vector<int>> &grid, int r,
            int c) {
  if (grid[r][c] == '#') {
    return;
  }
  if (r == grid.size() - 1 && c == grid.size() - 1) {
    // base case to stop
    ans.push_back(temp);
    return;
  }
  bool up = true, down = true, left = true, right = true;
  if (r == 0) {
    up = false;
  }
  if (r == grid.size() - 1) {
    down = false;
  }
  if (c == 0) {
    left = false;
  }
  if (c == grid.size() - 1) {
    right = false;
  }
  if (up && grid[r - 1][c] == 1) {
    // it means go up there is one
    int t = grid[r][c];
    grid[r][c] = '#';
    temp += "U";
    helper(temp, ans, grid, r - 1, c);
    temp.pop_back();
    grid[r][c] = t;
  }
  if (down && grid[r + 1][c] == 1) {
    // go down there is one
    int t = grid[r][c];
    grid[r][c] = '#';
    temp += "D";
    helper(temp, ans, grid, r + 1, c);
    temp.pop_back();
    grid[r][c] = t;
  }
  if (left && grid[r][c - 1] == 1) {
    // go to left
    int t = grid[r][c];
    grid[r][c] = '#';
    temp += "L";
    helper(temp, ans, grid, r, c - 1);
    temp.pop_back();
    grid[r][c] = t;
  }
  if (right && grid[r][c + 1] == 1) {
    // go to right and search
    int t = grid[r][c];
    grid[r][c] = '#';
    temp += "R";
    helper(temp, ans, grid, r, c + 1);
    temp.pop_back();
    grid[r][c] = t;
  }
}
vector<string> findPath(vector<vector<int>> &grid) {
  int n = grid.size();
  vector<string> result;
  string temp = "";
  if (grid[0][0] == 1) {
    // start from 0,0
    helper(temp, result, grid, 0, 0);
  } else {
    return {"-1"};
  }
  return result;
}
int main() {
  vector<vector<int>> grid = {
      {1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
  vector<string> result = findPath(grid);
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }
  return 0;
}
// this is the most optimal code for this approach
// #include <bits/stdc++.h>
// using namespace std;

// void helper(int r, int c, vector<vector<int>> &grid, int n, vector<string>
// &ans,
//             string &path, vector<vector<int>> &visited) {

//   // base case
//   if (r == n - 1 && c == n - 1) {
//     ans.push_back(path);
//     return;
//   }

//   // mark visited
//   visited[r][c] = 1;

//   // DOWN
//   if (r + 1 < n && grid[r + 1][c] == 1 && !visited[r + 1][c]) {
//     path.push_back('D');
//     helper(r + 1, c, grid, n, ans, path, visited);
//     path.pop_back();
//   }

//   // LEFT
//   if (c - 1 >= 0 && grid[r][c - 1] == 1 && !visited[r][c - 1]) {
//     path.push_back('L');
//     helper(r, c - 1, grid, n, ans, path, visited);
//     path.pop_back();
//   }

//   // RIGHT
//   if (c + 1 < n && grid[r][c + 1] == 1 && !visited[r][c + 1]) {
//     path.push_back('R');
//     helper(r, c + 1, grid, n, ans, path, visited);
//     path.pop_back();
//   }

//   // UP
//   if (r - 1 >= 0 && grid[r - 1][c] == 1 && !visited[r - 1][c]) {
//     path.push_back('U');
//     helper(r - 1, c, grid, n, ans, path, visited);
//     path.pop_back();
//   }

//   // backtrack
//   visited[r][c] = 0;
// }

// vector<string> findPath(vector<vector<int>> &grid) {
//   int n = grid.size();
//   vector<string> ans;

//   if (grid[0][0] == 0)
//     return ans;

//   vector<vector<int>> visited(n, vector<int>(n, 0));
//   string path = "";

//   helper(0, 0, grid, n, ans, path, visited);

//   return ans;
// }
