#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <utility>

using namespace std;

int main() {
  char c;
  vector<string> in;
  string acc;
  while ((c = getc(stdin)) != EOF) {
    if (c == '\n') {
      if (!acc.empty()) {
        in.push_back(acc);
      }
      acc.clear();
    } else {
      acc += c;
    }
  }

  unordered_map<char, vector<pair<int,int>>> loc;
  set<pair<int,int>> visited;
  int rbound = in.size();
  int cbound = in[0].size();
  int answer = 0;
  for(int i = 0; i < in.size(); i++) {
    for(int j = 0; j < in[i].size(); j++) {
      if (in[i][j] != '.') {
        if (loc.find(in[i][j]) == loc.end()) {
          loc[in[i][j]] = {pair<int,int>(i,j)};
        } else {
          for (int k = 0; k < loc[in[i][j]].size(); k++) {
            pair<int,int> antinode1((loc[in[i][j]][k].first - i) + loc[in[i][j]][k].first, (loc[in[i][j]][k].second - j) + loc[in[i][j]][k].second);
            pair<int,int> antinode2(-1*(loc[in[i][j]][k].first - i) + i, -1*(loc[in[i][j]][k].second - j) + j);
            if (antinode1.first >= 0 && antinode1.first < rbound && antinode1.second >= 0 && antinode1.second < cbound && visited.find(antinode1) == visited.end()) {
              visited.insert(antinode1);
              answer++;
            } 
            if (antinode2.first >= 0 && antinode2.first < rbound && antinode2.second >= 0 && antinode2.second < cbound && visited.find(antinode2) == visited.end()) {
              visited.insert(antinode2);
              answer++;
            }
          }
          loc[in[i][j]].push_back(pair<int,int>(i,j));
        }
      }
    }
  }
  cout << answer << endl;
  return 0;
}