#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

bool same_suffix(const string& str, const string& suffix) {
  if (suffix.size() > str.size()) return false;
  return equal(suffix.rbegin(), suffix.rend(), str.rbegin());
}

bool consider(ll target, vector<int> nums) {
  if (nums.size() == 1) {
    return target == nums[0];
  }

  if (target % nums[nums.size()-1] == 0 && 
      consider(target / nums[nums.size()-1], vector<int>(nums.begin(), nums.end()-1))) {
    return true;
  }

  if (target > nums[nums.size()-1] && 
      consider(target - nums[nums.size()-1], vector<int>(nums.begin(), nums.end()-1))) {
    return true;
  }

  string st = to_string(target);
  string lns = to_string(nums[nums.size()-1]);
  if (st.length() > lns.length() &&
      same_suffix(st, lns)) {
    string new_str = st.substr(0, st.length() - lns.length());
    if (consider(atoll(new_str.c_str()), vector<int>(nums.begin(), nums.end()-1))) {
      return true;
    }
  }

  return false;
}


int main() {
  string s;
  vector<int> nums;
  ll res = 0;
  ll answer = 0;
  while (getline(cin, s)) {
    for (int i = 0; i < (int) s.length(); i++) {
      if (s[i] == ':') {
        int acc = 0;
        for (int j = i + 2; j < (int) s.length(); j++) {
          if (s[j] == ' ') {
            nums.push_back(acc);
            acc = 0;
          } else {
            acc = acc * 10 + (s[j] - '0');
          }
        }
        nums.push_back(acc);  
        if (consider(res, nums)) {
          answer += res;
        }
        nums.clear();
        break;
      } else {
        res = res * 10 + (s[i] - '0');
      }
    }

    res = 0;
  }

  cout << answer << endl;
  return 0;
}