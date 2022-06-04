#include <bits/stdc++.h>
 
using namespace std;
#define int long long 
 
signed main() {
  int tt;
  cin >> tt;
  for(int i = 0; i < tt; ++i) {
    int n, m,s = 0;
    cin >> n >> m;
    vector<int> a(n), x(m);
    for(auto& it : a) {
      cin >> it;
      s += it;
    }
    for(auto& it : x) {
      cin >> it;
    }
    vector<int> pre;
    pre.push_back(a[0]);
    for(int i = 1; i < n; ++i) {
      pre.push_back(pre[i-1] + a[i]);
    }
    map<int, int> mp;
    for(int i = 0; i < n; ++i) {
      if(mp[pre[i]] > 0) continue;
      mp[pre[i]] = i;
    }
    int mx = pre[0];
    
    vector<int> b;
    for(int x : pre) b.push_back(x);
    
    sort(b.begin(), b.end());
    
    vector<pair<int, int>> ret;
    for(int i = 0; i < n; ++i) {
      ret.emplace_back(pre[i], i);
    }
    sort(ret.begin(), ret.end());
    vector<int> suff(n);
    suff[n-1] = ret[n-1].second;
    for(int i = n-2; i >= 0; --i) {
      if(1) {
        suff[i] = min(suff[i+1], ret[i].second);
      }
    }
     
    for(int xx : pre) mx = max(mx, xx);
 
    for(int l : x) {
      int in = lower_bound(b.begin(), b.end(), l) - b.begin();
      if(in>=0 && in<n) {
        cout << suff[in] << " ";
      } else {
        if(pre.back() <= 0) {
          cout << "-1 ";
        } else {
          int find = l - mx;
          int ans = find / pre.back();
          ans *= n;
          int kk = find % pre.back() + mx;
          if(kk > mx) {
            ans += n;
            kk -= pre.back();
            //cout << "SDSD  " << kk << '\n';
          } 
          int in = lower_bound(b.begin(), b.end(), kk) - b.begin();
          int val = b[in];
          cout << ans + suff[in] << " " ;
        }
      }
    }
    cout << '\n';
  }
}    
    