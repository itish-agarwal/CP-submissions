
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

//ABCDEFGHIJKLMNOPQRSTUVWXYZ


const int nax = 1e5 + 66;
const int are = 26;
string s;
int n;
int dp[nax][are];

int f(int pos, int should) {
  if(dp[pos][should] > -1) {
    return dp[pos][should];
  }
  if(s[pos]!=(should+'a')) {
    dp[pos][should] = 0;
    return 0;
  }
  if(pos==0) {
    dp[pos][should] = 1;
    return 1;
  }
  int res = 0;
  int prev = should-1;
  if(prev < 0) {
    prev += 26;
  }
  res += f(pos-1, prev);
  dp[pos][should] = res + 1;
  return res;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    cin >> n >> s;
    for(int i = 0; i <= n; i++) {
      for(int j = 0; j <= are; j++) {
        dp[i][j] = -1;
      }
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
      int add = f(i, s[i]-'a');
      ans += f(i, s[i]-'a');
    }
    cout << ans << '\n';
  }
  return 0;
}
    
