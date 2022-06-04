#include <bits/stdc++.h>
 
using namespace std;
#define int long long 
 
string L, R;
int len;
 
int dp[20][2][2][11][11];
 
int rec(int id, int lo, int hi, int first, int last) {
  if(id == len) {
    return first%2 == last%2;
  }
  if(dp[id][lo][hi][first][last] <= -1) {
    int ans = 0;
    int loLim = 0, hiLim = 9;
    if(hi) {
      hiLim = R[id] - '0';
    }
    if(lo) {
      loLim = L[id] - '0';
    }
    for(int i = loLim; i <= hiLim; i++) {
      int newHigh = hi, newLow = lo;
      if(i != hiLim) {
        newHigh = 0;
      }
      if(i != loLim) {
        newLow = 0;
      }
      ans += rec(id + 1, newLow, newHigh, (id == 0 ? i : first), i);  
    }
    dp[id][lo][hi][first][last] = ans;
  }
  return dp[id][lo][hi][first][last];
}
signed main() {
  
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  cin >> R;
  L = "1";
 
  int n1 = L.size();
  int n2 = R.size();
  vector<string> ret{L};
  for(int i = n1; i < n2; i++) {
    string t = string(i, '9');
    string s = '1' + string(i, '0');      
    ret.push_back(t);
    ret.push_back(s);
  }
  ret.push_back(R);
  int answer = 0;
 
  for(int i = 1; i < (int)ret.size(); i += 1) {
    L = ret[i - 1], R = ret[i];
    len = L.size();
    memset(dp, -1, sizeof(dp));
    // answer += rec(0, 1, 1, -1);
    answer += rec(0, 1, 1, 0, 0);
  }
  cout << answer << '\n';
}