#include <bits/stdc++.h>

using namespace std;
#define int long long

const int MAX = 1e9 + 7;
int len, num;
string L, R;

int dp1[35][2][2], dp2[35][2][2];

int numbers(int id, int lo, int hi) {
  if(id == len) 
    return 1;

  if(dp1[id][lo][hi] > -1) 
    return dp1[id][lo][hi];

  int res = 0, lo_lim = 0, hi_lim = 1;
  if(lo) 
    lo_lim = L[id] - '0';
  if(hi)
    hi_lim = R[id] - '0';

  for(int b = lo_lim; b <= hi_lim; ++b) {
    int new_low = lo, new_high = hi;
    if(b != lo_lim)
      new_low = 0;
    if(b != hi_lim)
      new_high = 0;

    res += numbers(id + 1, new_low, new_high);
  }

  return dp1[id][lo][hi] = res;
}
int rec(int id, int lo, int hi) {
  if(id == len) 
    return 0;

  if(dp2[id][lo][hi] > -1) 
    return dp2[id][lo][hi];

  int res = 0, lo_lim = 0, hi_lim = 1;
  if(lo)
    lo_lim = L[id] - '0';
  if(hi)
    hi_lim = R[id] - '0';

  for(int b = lo_lim; b <= hi_lim; ++b) {
    int new_low = lo, new_high = hi;
    if(b != lo_lim)
      new_low = 0;
    if(b != hi_lim) 
      new_high = 0;

    res += (id % 2 == 0) * b * numbers(id + 1, new_low, new_high)  + rec(id + 1, new_low, new_high);
  }

  return dp2[id][lo][hi] = res;
}
int upto(int k) {
  vector<string> beg;
  int p = 2;
  while(p <= k) {
    int bits = 0, x = p;
    while(x) {
      bits++;
      x /= 2;
    }
    string b = "1", e = "1";
    for(int j = 0; j < bits - 1; ++j) { 
      b.push_back('0');
      e.push_back('1');
    }
    beg.emplace_back(b);
    beg.emplace_back(e);
    p *= 2;
  }

  if(!beg.empty())
    beg.pop_back();

  string px = "";
  while(k > 0) {
    px.push_back(k%2 + '0');
    k /= 2;
  }

  reverse(px.begin(), px.end());
  beg.emplace_back(px);

  int res = 1;

  for(int i = 1; i < (int) beg.size(); i += 2) {
    L = beg[i-1];
    R = beg[i];
    len = L.size();
    memset(dp1, -1, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));
    res += rec(0, 1, 1);
  }

  return res;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while(T--) {
    int K;
    cin >> K;

    int low = 1, high = MAX, ans = high;

    while(low <= high) {
      int mid = low + (high - low) / 2;
      if(upto(mid) < K) {
        low = mid + 1;
      } 
      else {
        high = mid - 1;
        ans = mid;
      }
    }

    cout << ans << '\n';
  }
}

