#include <bits/stdc++.h>

using namespace std;
#define int long long

int power(int a, int b) {
  if(b==0) return 1;
  int res = power(a, b/2);
  res *= res;
  if(b % 2) {
    res *= a;
  }
  return res;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for(int i = 1; i <= 38; i++) {
    for(int j = 1; j<= 26; j++) {
      if(power(3LL, i) + power(5LL, j) == n) {
        if(power(3LL, i) > 0 && power(5LL, j) > 0) {
          cout << i << " " << j << endl;
          return 0;
        }
      }
    }
  }
  cout << "-1\n";
  return 0;
}

