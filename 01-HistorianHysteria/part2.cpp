#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#define BUFFER_SIZE 100
#define INPUT_SIZE 1000

int main() {
  std::ifstream input("puzzle_input.txt");
  char buffer[BUFFER_SIZE]; 
  int left[INPUT_SIZE] = {0}; 
  int right[INPUT_SIZE] = {0};
  size_t lptr = 0; 
  size_t rptr = 0;

  // parse input
  if (input.is_open()) {
    while (input >> buffer) {
      if (lptr <= rptr && lptr < INPUT_SIZE) {
        left[lptr++] = std::atoi(buffer);
      } else if (rptr < INPUT_SIZE) {
        right[rptr++] = std::atoi(buffer);
      } else {
        std::cerr << "INPUT EXCEEDS BUFFER LIMIT\n"; 
        break;
      }
    }
  } else {
    std::cerr << "CANT OPEN FILE\n";
    return 1;
  }

  std::sort(left, left + lptr);
  std::sort(right, right + rptr);

  int result = 0;

  size_t lidx = 0; 
  size_t ridx = 0;

  while (lidx < lptr) {
    int matches = 0;
    int current = left[lidx];

    // seek matches 
    while (ridx < rptr && right[ridx] <= current) {
      if (right[ridx] == current) {
        matches++;
      }
      ridx++;
    }
    
    std::cout << current << " " << matches << "\n";
    result += current * matches; 

    // reset matches and seek next unique left value
    matches = 0;
    while (lidx < lptr && left[lidx] == current) {
      lidx++;
    }
  } 

  std::cout << "RESULT = " << result << "\n";  

  return 0;
}