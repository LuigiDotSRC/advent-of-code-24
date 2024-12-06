#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

void consider(vector<int> row, unordered_map<int, vector<int>> map, int &answer) {
  set<int> inRow (row.begin(), row.end());
  set<int> visited;
  for (int i = 0; i < row.size(); i++) {
    visited.insert(row[i]);

    // check that all the numbers that precede current num are in the row and have been visited
    for (int j = 0; j < map[row[i]].size(); j++) {
      if (inRow.find(map[row[i]][j]) != inRow.end()) {
        if (visited.find(map[row[i]][j]) == visited.end()) {
          // number is in current row and could not find it preceding current num

          for (int k : row) { cout << k << " "; }
          cout << endl;
          return;
        }
      }
    }
  }
  // row is valid
  answer += row[row.size() / 2];
}

int main() {
  char c;
  unordered_map<int, vector<int>> map;
  int num = 0;
  int val = 0;

  // parse section 1
  while ((c = getc(stdin)) != EOF) {
    if (c == '\n') {
      if (val && num) {
        map[num].push_back(val);
        val = 0;
        num = 0; 
      } else {
        break;
      }
    }
    else if (c == '|') {
      val = num;
      num = 0;
    }
    else if (isdigit(c)) {
      num = num * 10 + (c - '0'); 
    }
  }

  // parse seciton 2
  num = 0;
  int answer = 0;
  vector<int> row;
  while ((c = getc(stdin)) != EOF) {
    if (isdigit(c)) {
      num = num * 10 + (c - '0');
    }
    else if (c == ',') {
      row.push_back(num);
      num = 0;
    } 
    else if (c == '\n') {
      row.push_back(num);
      
      consider(row, map, answer); 
      num = 0;
      row.clear();
    }
  }
  printf("%d\n", answer);
  return 0;
}