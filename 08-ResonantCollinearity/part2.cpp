#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <utility>

using namespace std;

// 621 too low
// 913 too low

int rbound;
int cbound;
set<pair<int,int>> visited;
int answer = 0;

void find_antinodes(const vector<pair<int,int>> ants, int i, int j) {
  // cout << "rbound: " << rbound << " cbound: " << cbound << endl;
  for(int k = 0; k < ants.size(); k++) {
    pair<int,int> dist(ants[k].first - i, ants[k].second - j);
    pair<int,int> antinode1(2*ants[k].first - i, 2*ants[k].second - j);
    while (1) {
      cout << ants[k].first + dist.first << " " << ants[k].second + dist.second << endl;
      if (
        antinode1.first < 0 || antinode1.first >= rbound ||
        antinode1.second < 0 || antinode1.second >= cbound ||
        visited.find(antinode1) != visited.end()
      ) {
        break;
      }
      cout << ants[k].first + dist.first << " " << ants[k].second + dist.second << endl;
      visited.insert(antinode1);
      answer++;
      antinode1.first += dist.first;
      antinode1.second += dist.second;
    }

    dist.first = -1*(ants[k].first - i);
    dist.second = -1*(ants[k].second - j);
    pair<int,int> antinode2(i + dist.first, j + dist.second);
    while (1) {
      cout << i + dist.first << " " << j + dist.second << endl;
      if (
        antinode2.first < 0 || antinode2.first >= rbound ||
        antinode2.second< 0 || antinode2.second >= cbound ||
        visited.find(antinode2) != visited.end()
      ) {
        break;
      }
      // cout << dist.first << " " << dist.second << endl;
      visited.insert(antinode2);
      answer++;
      // mul++;
      antinode2.first += dist.first;
      antinode2.second += dist.second;
    }
  }
}

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
  rbound = in.size();
  cbound = in[0].size();
  for(int i = 0; i < in.size(); i++) {
    for(int j = 0; j < in[i].size(); j++) {
      if (in[i][j] != '.') {
        if (loc.find(in[i][j]) == loc.end()) {
          loc[in[i][j]] = {pair<int,int>(i,j)};
          visited.insert(pair<int,int>(i,j));
        } else {
          for (int k = 0; k < loc[in[i][j]].size(); k++) {
            find_antinodes(loc[in[i][j]], i, j);
            visited.insert(pair<int,int>(i,j));
          }
          loc[in[i][j]].push_back(pair<int,int>(i,j));
        }
      }
    }
  }

  for(int i = 0; i < rbound; i++) {
    for(int j = 0; j < cbound; j++) {
      if(visited.find(pair<int,int>(i,j)) != visited.end()) {
        cout << "#";
      } else {
        cout << ".";
      }
    }
    cout << endl;
  }
  cout << answer << " " << visited.size() << endl;
  return 0;
}