#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif

using namespace std;
string L, R;
int len;

int dp[9][2][2][9];

int rec(int id, int lo, int hi, int cnt) {
  if(id == len) {
    return cnt;
  }
  if(dp[id][lo][hi][cnt] <= -1) {
    int ans = 0;
    int loLim = 0, hiLim = 9;
    if(lo) loLim = L[id] - '0';
    if(hi) hiLim = R[id] - '0';
    for(int i = loLim; i <= hiLim; i++) {
      int newLow = lo, newHigh = hi;
      if(i!=loLim) newLow = 0;
      if(i!=hiLim) newHigh = 0;
      ans += rec(id+1, newLow, newHigh, cnt + (i==7));
    }
    dp[id][lo][hi][cnt] = ans;
  }
  return dp[id][lo][hi][cnt];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    cin >> L >> R;
    int n1 = L.size();
    int n2 = R.size();
    vector<string> ret{L};
    int ans = 0;
    for(int i = n1; i < n2; i++) {
      string t = string(i, '9');
      string s = '1' + string(i, '0');      
      ret.push_back(t);
      ret.push_back(s);
    }
    ret.push_back(R);
    int answer = 0;
    for(int i = 1; i < (int)ret.size(); i += 2) {
      L = ret[i-1];
      R = ret[i];
      len = L.size();
      memset(dp, -1, sizeof(dp));
      answer += rec(0, 1, 1, 0);
    }
    cout << answer << '\n';
  }
  return 0;
}
