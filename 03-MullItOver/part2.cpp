#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string.h>
#include <cctype>
using namespace std;

// code example written by Errichto Algorithms https://www.youtube.com/watch?v=U6x7zpOGkBU

int getNumber(string s, int& i) {
  int x = 0;
  // integer overflow protection
  while (x < 1000 && isdigit(s[i])) { 
    x = 10 * x + (s[i] - '0'); // method to parse digit to end of int
    i++;
  }
  if (1 <= x && x <= 999) {
    return x;
  }
  return -1;
}

int main() {
  string s;
  int answer;
  char c;
  while (scanf("%c", &c) != EOF) {
    s += c; 
  }
  s += "###########################"; // prevent indexing error

  int n = (int) s.length();
  bool enable = true;
  for (int i = 0; i < n - 7; i++) {
    if (s.substr(i, 4) == "do()") {
      enable = true;
    }
    if (s.substr(i, 7) == "don\'t()") {
      enable = false;
    }
    if (enable && s[i] == 'm') {
      if (s[i+1] == 'u' && s[i+2] == 'l' && s[i+3] == '(') {
        i += 4; // skip past "mul("
        int x = getNumber(s, i); // return the first complete number found, update reference to i
        if (s[i] == ',') {
          i += 1;
          int y = getNumber(s, i);
          if (s[i] == ')') {
            if (x != -1 && y != -1) {
              answer += x * y;
            }
          }
        }
      }
    }
  }
  printf("%d\n", answer);
  return 0;
}