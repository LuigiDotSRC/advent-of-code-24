#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

// Errichto Algorithms https://www.youtube.com/watch?v=UwV47y3GqsY

vector<pair<int, int>> dirs = {{-1,0},{0,1},{1,0},{0,-1}};

int main() {
  int H = 130;
  vector<string> a(H);
  for (int i = 0; i < H; i++) {
    cin >> a[i]; 
  }
  int W = a[0].length();

  pair<int, int> start_me{-1, -1};
  int dir = 0;
  for (int row = 0; row < H; row++) {
    for (int col = 0; col < W; col++) {
      if (a[row][col] == '^') {
        start_me = {row,col};
        a[row][col] = '.';
      }
    }
  }

  auto solveCycle = [&]() {
    pair<int,int> me = start_me;
    int dir = 0;
    
    set<vector<int>> vis;
    int turns = 0;
    while (1) {
      turns++;
      // if (!vis.insert(vector<int>{me.first, me.second, dir}).second) {
      //   return true;
      // }
      if (turns == 100'000) {
        return true;
      }
      int r2 = me.first + dirs[dir].first;
      int c2 = me.second + dirs[dir].second;
      if (!(0 <= r2 && r2 < H && 0 <= c2 && c2 < W)) {
        return false;
      }
      if (a[r2][c2] == '.') {
        me = {r2, c2};
      }
      else {
        dir = (dir + 1) % 4;
      }
    }
  };

  int answer = 0;
  for (int row = 0; row < H; row++) {
    for (int col = 0; col < W; col++) {
      if (a[row][col] == '.' && start_me != make_pair(row,col)) {
        a[row][col] = '#';
        if (solveCycle()) {
          answer++;
        }
        a[row][col] = '.';
      }
    }
  }
  
  cout << answer << "\n";
  return 0;
}