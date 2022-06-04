#include <bits/stdc++.h>

using namespace std;

int main() {
  int tt;
  scanf("%d", &tt);
  while(tt--) {
    int n;
    scanf("%d", &n);
    n *= 4; n --;
    vector<int> x(n), y(n);
    map<int, int> cx, cy;
    for(int i = 0; i < n; ++i) {
      scanf("%d%d", &x[i], &y[i]);
      cx[x[i]]++; cy[y[i]]++;
    }
    for(int& p : x) {
      if(cx[p] & 1) {
        printf("%d ", p);
        break;
      }
    }
    for(int& p : y) {
      if(cy[p] & 1) {
        printf("%d\n", p);
        break;
      }
    }
  }
  return 0;
}
