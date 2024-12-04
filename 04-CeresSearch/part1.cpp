#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector<string> s;
  string acc;
  char c;
  while ((c = getc(stdin)) != EOF) {
    if (c == '\n') {
      s.push_back(acc);
      acc.clear();
    } else {
      acc.push_back(c);
    }
  }

  int answer = 0;
  for (int i = 0; i < s.size(); i++) {
    for (int j = 0; j < s[i].size(); j++) {
      // horizontal XMAS
      if (j + 3 < s[i].size() && s[i][j] == 'X' && s[i][j+1] == 'M' && s[i][j+2] == 'A' && s[i][j+3] == 'S') {
        answer++;
      }
      // vertical XMAS
      if (i + 3 < s.size() && s[i][j] == 'X' && s[i+1][j] == 'M' && s[i+2][j] == 'A' && s[i+3][j] == 'S') {
        answer++;
      }
    
      // horizontal SAMX
      if (j + 3 < s[i].size() && s[i][j] == 'S' && s[i][j+1] == 'A' && s[i][j+2] == 'M' && s[i][j+3] == 'X') {
        answer++;
      }
      // vertical SAMX
      if (i + 3 < s.size() && s[i][j] == 'S' && s[i+1][j] == 'A' && s[i+2][j] == 'M' && s[i+3][j] == 'X') {
        answer++;
      }

      // diagonals
      if (i - 3 >= 0 && j + 3 < s[i].size() && s[i][j] == 'X' && s[i-1][j+1] == 'M' && s[i-2][j+2] == 'A' && s[i-3][j+3] == 'S') {
        answer++;
      }
      if (i - 3 >= 0 && j + 3 < s[i].size() && s[i][j] == 'S' && s[i-1][j+1] == 'A' && s[i-2][j+2] == 'M' && s[i-3][j+3] == 'X') {
        answer++;
      }
      if (i + 3 < s.size() && j + 3 < s[i].size() && s[i][j] == 'X' && s[i+1][j+1] == 'M' && s[i+2][j+2] == 'A' && s[i+3][j+3] == 'S') {
        answer++;
      }
      if (i + 3 < s.size() && j + 3 < s[i].size() && s[i][j] == 'S' && s[i+1][j+1] == 'A' && s[i+2][j+2] == 'M' && s[i+3][j+3] == 'X') {
        answer++;
      }
    }
  }
  printf("%d\n", answer);
  return 0;    
}