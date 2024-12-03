#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cstring>
#define BUFFER_SIZE 100
#define INPUT_SIZE 1000
#define MAX_LEVEL_LEN 9

int main() {
  std::ifstream input("puzzle_input.txt");  
  if (!input.is_open()) {
    std::cerr << "Failed to open file." << std::endl; 
    return 1;
  }

  char buffer[BUFFER_SIZE];
  memset(buffer, '\0', BUFFER_SIZE);
  size_t bptr = 0;

  int level[MAX_LEVEL_LEN];
  size_t lptr = 0;

  char c;
  int safe = 1;
  int result = 0;

  while (input.get(c)) {
    if (c != '\n' && c != ' ') {
      if (bptr >= BUFFER_SIZE - 1) {
        std::cerr << "BUFFER OVERFLOW\n";
        return 1;
      }
      buffer[bptr++] = c; 
    } 
    
    if (c == ' ' || c == '\n') {
      if (bptr > 0) {
        level[lptr++] = std::atoi(buffer);
        bptr = 0;
        memset(buffer, '\0', BUFFER_SIZE);
      }
    } 
    
    if (c == '\n') {
      if (level[0] >= level[1]) {
        for (size_t i = 1; i < lptr; i++) {
          if (level[i - 1] < level[i] || level[i - 1] - level[i] > 3 || level[i - 1] == level[i]) {
            safe = 0;
            break;
          }
        }
      } else if (level[0] < level[1]) {
        for (size_t i = 1; i < lptr; i++) {
          if (level[i - 1] > level[i] || level[i] - level[i - 1] > 3 || level[i - 1] == level[i]) {
            safe = 0;
            break;
          }
        }
      }

      for (size_t i = 0; i < lptr; i++) {
        std::cout << level[i] << ' ';
      }
      if (safe) {
        std::cout << " SAFE" << std::endl;
      } else {
        std::cout << " UNSAFE" << std::endl;
      }
      result += safe;

      safe = 1;
      lptr = 0;
    }
  }

  // handle remaining data (last char of input is not \n)
  if (bptr > 0) {
    if (level[0] >= level[1]) {
      for (size_t i = 1; i < lptr; i++) {
        if (level[i - 1] < level[i] || level[i - 1] - level[i] > 3 || level[i - 1] == level[i]) {
          safe = 0;
          break;
        }
      }
    } else if (level[0] < level[1]) {
      for (size_t i = 1; i < lptr; i++) {
        if (level[i - 1] > level[i] || level[i] - level[i - 1] > 3 || level[i - 1] == level[i]) {
          safe = 0;
          break;
        }
      }
    }

    for (size_t i = 0; i < lptr; i++) {
      std::cout << level[i] << ' ';
    }
    if (safe) {
      std::cout << " SAFE" << std::endl;
    } else {
      std::cout << " UNSAFE" << std::endl;
    }
    result += safe;
  }

  std::cout << "RESULT: " << result << std::endl;

  input.close();
  return 0;
}