#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string.h>
#include <cctype>
using namespace std;

int main() {
  int answer = 0;
  string buffer;
  char c;
  bool found_prefix = false;
  bool found_arg1 = false;

  int a, b;

  while((c = getc(stdin)) != EOF) {
    buffer.push_back(c);

    if (!found_prefix) {
      // current buffer exceeds length of "mul("
      if (buffer.size() > 4) {
        buffer.erase(buffer.begin()); 
      }

      if (buffer == "mul(") {
        found_prefix = true;
        buffer.clear(); 
      }
    } else {
      if (!found_arg1) {
        if (c == ',') {
          found_arg1 = true; 
          cout << buffer << " A \n";
          a = stoi(buffer.substr(0, buffer.size() - 1));
          buffer.clear();
        }
        else if (!isdigit(c)) {
          found_prefix = false;
          buffer.clear();
        }
      } else {
        if (c == ')') {
          cout << buffer << " B \n";
          b = stoi(buffer.substr(0, buffer.size() - 1));

          answer += a * b;

          a = 0; 
          b = 0;
          found_arg1 = false; 
          found_prefix = false;
          buffer.clear();

        }
        else if (!isdigit(c)) {
          a = 0;
          found_prefix = false;
          found_arg1 = false; 
          buffer.clear();
        }
      }
    }
  }

  printf("%d\n", answer);
  return 0;
}