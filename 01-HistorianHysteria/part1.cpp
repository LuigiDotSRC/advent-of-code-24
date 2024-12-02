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

  size_t min_size = std::min(lptr, rptr);
  for (size_t i = 0; i < min_size; i++) {
    int difference = std::abs(left[i] - right[i]);
    result += difference;
    std::cout << "LEFT: " << left[i] << " RIGHT: " << right[i] << " DIFFERNECE: " << difference << "\n";
  }

  std::cout << "RESULT = " << result << "\n";

  return 0;
}