#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    // vector<int> in{-1};
    vector<int> in;
    for(int i = 0; i < n; i++) {
      if(s[i] == 'W') {
        in.push_back(i);
      }
    }

    vector<pair<int, int>> ret;

    for(int i = 1; i < in.size(); i++) {
      int sz = in[i] - in[i-1] - 1;
      if(sz > 0) {
        ret.emplace_back(sz, in[i-1]);
      }
    }
    sort(ret.begin(), ret.end());
    for(auto it : ret) {
      int sz = it.first;
      int can = min(k, sz);
      k -= sz;
      int index = it.second + 1;
      for(int j = index; j < index + can; j++) {
        s[j] = 'W';
      }
    }
    int ans = 0;

    int f = -1;
    for(int i = 0; i < n; i++) {
      if(s[i]=='W') {
        f = i;
        break;
      }
    }

    for(int j = f - 1; j >= 0; --j) {
      if(k > 0) {
        s[j] = 'W';
        k--;
      } else {
        break;
      }
    }

    f = -1;
    for(int i = n - 1; i >= 0; --i) {
      if(s[i] == 'W') {
        f = i;
        break;
      }
    }
    for(int j = f + 1; j < n; ++j) {
      if(k > 0) {
        s[j] = 'W';
        k--;
      } else {
        break;
      }
    }

    for(int i = 0; i < n; i++) {
      if(s[i] == 'W') {
        if(i==0) {
          ans++;
        } else {
          if(s[i-1] == 'W') {
            ans += 2;
          } else {
            ans++;
          }
        }
      }
    }

    cout << ans << '\n';
  }
}