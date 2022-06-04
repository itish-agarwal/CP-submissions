
#include <bits/stdc++.h>

using namespace std;
#define int int64_t 

ostream& operator << (ostream& stream, const vector<int>& v) {
  for(int x : v) {
    stream << x << " ";
  }
  return stream;
}

//ostream& operator << (ostream& stream, const int *a) {
  //for(int i = 0; i < n; i++) {
    //stream << *(a + i) <<  " ";
  //}
  //return stream;
//}
int power(int a, int b) {
  if(b == 0) {
    return 1;
  }
  int res = power(a, b/2);
  res *= res;
  if(b % 2) {
    res *= a;
  }
  return res;
}

const int nax = 1e3 + 33;
int dp[nax][nax];
int n, k;

int f(int left, int last) {
  if(dp[left][last] > 0) {
    return dp[left][last];
  }
  if(left == 0) {
    dp[left][last] = 1;
    return 1;
  }
  int ans = 0;
  for(int can = last + 1; can <= n; can++) {
    if(power(can, k) <= left) {
      ans += f(left-power(can, k), can);
    }
  }
  dp[left][last] = ans;
  return ans;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    cin >> n >> k;
    for(int i = 0; i <= n; i++) {
      for(int j = 0; j <= n; j++) {
        dp[i][j] = 0;
      }
    }
    cout << f(n, 0) << '\n';
  }
  return 0;
}
