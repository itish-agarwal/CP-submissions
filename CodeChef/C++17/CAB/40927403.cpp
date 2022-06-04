#include <bits/stdc++.h>

using namespace std;
#define int int64_t
vector<int> power(30);

void solve() {
  int n, k;
  cin >> n >> k;
  //length n and score k
  int mn = n;
  int mx = n*power[25];
  if(k>=mn && k<=mx) {
    vector<int> has;
    int p = 0;
    int kk = k;
    while(kk > 0) {
      if(kk % 2) {
        has.push_back(p);
      }
      kk /= 2;
      p++;
    }
    if((int)has.size() > n) {
      cout << "-1\n";
      return;
    }
    priority_queue<int> s;
    for(int x : has) {
      s.push(x);
    }
    while(s.size() < n) {
      int most = s.top();
      s.pop();
      s.push(most-1);
      s.push(most-1);
    }
    string ans = "";
    while(!s.empty()) {
      int d = s.top();
      ans += char(d + 'a');
      s.pop();
    }
    sort(ans.begin(), ans.end());
    cout << ans << '\n';
    return;    
  } else {
    cout << "-1\n";
  }
  return;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  power[0] = 1;
  for(int i = 1; i < 30; i++) {
    power[i] = 2*power[i-1];
  }
  int tt;
  cin >> tt;
  while(tt--) {
    solve();
  }
}
