#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif

using namespace std;
#define int long long 

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    
     int n;
     cin >> n;
     vector<int> a(n);
     for(auto& it : a) cin >> it;
     sort(a.begin(), a.end());
     for(int it : a) cout << it << " " ;
     cout << '\n';
   }
 }
