#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool can_obtain(long long target, vector<int> nums) {
  if (nums.size() == 1) {
    return target == nums[0];
  }
  if (target % nums[nums.size()-1] == 0 && can_obtain(target / nums[nums.size()-1], vector<int>(nums.begin(), nums.end()-1))) {
    return true;
  }
  if (target > nums[-1] && can_obtain(target - nums[nums.size()-1], vector<int>(nums.begin(), nums.end()-1))) {
    return true;
  }
  return false;
}

int main() {
  string s;
  vector<int> nums;
  long long res = 0;
  long long answer = 0;
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
        if (can_obtain(res, nums)) {
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