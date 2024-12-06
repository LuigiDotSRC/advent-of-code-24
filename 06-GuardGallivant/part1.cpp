#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<string> in;
  string s;
  int answer = 1;
  int x = 0;
  int y = 0;

  int row = 0;
  int col = 0;
  char c;
  while ((c = getc(stdin)) != EOF) {
    if (c == '\n') {
      if (s.size() > 0) {
        row++;
        col = 0;
        in.push_back(s);
        s.clear();
      } 
      else {
        break;
      }
    }
    else if (c == '^') {
      x = col++;
      y = row;
      s.push_back(c);
    } else {
      col++;
      s.push_back(c);
    }
  }

  int facing = 0; // 0 == N, 1 == E, 2 == S, 3 == W
  while (1) {
    if (facing == 0) {
      if (y - 1 < -1) {
        break;
      } 
      else if (in[y - 1][x] == '#') {
        facing = (facing + 1) % 4;
      }
      else {
        if (in[y][x] != 'X') {
          in[y][x] = 'X';
          answer++;
        } 
        y -= 1;
      }
    } 
    else if (facing == 1) {
      if (x + 1 > (int) in[0].size() - 1) {
        break;
      } 
      else if (in[y][x + 1] == '#') {
        facing = (facing + 1) % 4;
      }
      else {
        if (in[y][x] != 'X') {
          in[y][x] = 'X';
          answer++;
        } 
        x += 1;
      }
    }
    else if (facing == 2) {
      if (y + 1 > (int) in[0].size() - 1) {
        break;
      } 
      else if (in[y + 1][x] == '#') {
        facing = (facing + 1) % 4;
      }
      else {
        if (in[y][x] != 'X') {
          in[y][x] = 'X';
          answer++;
        } 
        y += 1;
      }
    }
    else if (facing == 3) {
      if (x - 1 < -1) {
        break;
      } 
      else if (in[y][x - 1] == '#') {
        facing = (facing + 1) % 4;
      }
      else {
        if (in[y][x] != 'X') {
          in[y][x] = 'X';
          answer++;
        } 
        x -= 1;
      }
    }
  }
  
  cout << answer << endl;  
  return 0;
}