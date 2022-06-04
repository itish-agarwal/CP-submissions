#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    for(int i = 0; i < m; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    for(int x : b) {
      a.push_back(x);
    }
    int lo = n, hi = m, ans = hi;
    
    auto check = [&](int len) {
      vector<int> cnt(n + 1);
      int d = 0;
      for(int i = 0; i < len; i++) {
        cnt[a[i]]++;
        if(cnt[a[i]] == 1) {
          d += 1;
        }
      }
      if(d == n && len - 1 >= m) {
        return true;
      }
      for(int i = len; i < (int)a.size(); i++) {
        cnt[a[i]]++;
        if(cnt[a[i]] == 1) {
          d += 1;
        }
        cnt[a[i - len]]--;
        if(cnt[a[i - len]] == 0) {
          d--;
        }
        if(d == n && ((i == m - 1) || (i - len + 1 == m) || (i >= m && i - len + 1 <= m - 1))) {
          return true;
        }
      }  
      return false;
    };  
    while(lo <= hi) {
      int mid = (lo + hi)/2;
      if(check(mid)) {
        ans = mid;
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
    cout << ans << '\n';    
  }
}
