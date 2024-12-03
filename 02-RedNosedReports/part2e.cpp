#include <stdio.h>
#include <stdlib.h>
#include <vector>
#define INPUT_SIZE 1000
using namespace std;

// code example written by Errichto Algorithms https://www.youtube.com/watch?v=0H524GLePNc&t=594s

int isOk(vector<int> a) {
  int k = (int) a.size();
  int ok = 1;
  int only_inc = 1;
  int only_dec = 1;
  for (int j = 0; j < k - 1; j++) {
    int diff = a[j+1] - a[j];
    if (diff > 0) {
      only_dec = 0;
    }
    if (diff < 0) {
      only_inc = 0;
    }
    if (!(1 <= abs(diff) && abs(diff) <= 3)) {
      ok = 0;
      break;
    }
  } 
  return ok && (only_inc || only_dec);
}

int main() {
  int n = INPUT_SIZE;
  int answer = 0;
  for (int i = 0; i < n; i++) {
    vector<int> a;
    while (1) {
      int x;
      scanf("%d", &x);
      a.push_back(x);
      char c;
      scanf("%c", &c); 
      if (c == '\n' || c == EOF) {
        break;
      }
    }
    int anyOk = 0;
    auto consider = [&](int j) {
      vector<int> b = a;
      b.erase(b.begin() + j);
      if (isOk(b)) {
        anyOk = 1;
      }
    };
    int k = (int) a.size();
    consider(0);
    for (int j = 0; j < k - 1; j++) {
      int diff = a[j+1] - a[j];
      if (abs(diff) < 1 || abs(diff) > 3) {
        consider(j);
        consider(j+1);
        break;
      }
      if (j + 2 < k) {
        int diff2 = a[j+2] - a[j+1];
        if ((diff > 0) != (diff2 > 0)) {
          consider(j);
          consider(j + 1);
          consider(j + 2);
          break;
        }
      }
    }
    if (anyOk) {
      answer++;
    }
  }
  printf("%d\n", answer);
  return 0;
}