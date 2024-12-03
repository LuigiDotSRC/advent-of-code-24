#include <stdio.h>
#include <stdlib.h>
#include <vector>
#define INPUT_SIZE 1000
using namespace std;

// code example written by Errichto Algorithms https://www.youtube.com/watch?v=0H524GLePNc&t=594s

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
    if (ok && (only_inc || only_dec)) {
      answer++;
    }
  }
  printf("%d\n", answer);
  return 0;
}