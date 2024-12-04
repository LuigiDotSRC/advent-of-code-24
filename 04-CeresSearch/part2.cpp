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
      if (i - 2 >= 0 && j + 2 < s[i].size()) {
        if (
          ((s[i][j] == 'M' && s[i-1][j+1] == 'A' && s[i-2][j+2] == 'S') || (s[i][j] == 'S' && s[i-1][j+1] == 'A' && s[i-2][j+2] == 'M')) &&
          ((s[i-2][j] == 'M' && s[i-1][j+1] == 'A' && s[i][j+2] == 'S') || (s[i-2][j] == 'S' && s[i-1][j+1] == 'A' && s[i][j+2] == 'M')) 
        ) {
          answer++;
        }
      }
    }
  }
  printf("%d\n", answer);
  return 0;    
}