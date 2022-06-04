#include <bits/stdc++.h>

using namespace std;
#define int long long 

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n;
  cin >> n;
  int a[n], b[n], c[n];

  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for(int i = 0; i < n; i++) {
    cin >> c[i];
  }
  int d[n];
  for(int i = 0; i < n; i++) {
    d[i] = b[c[i]-1];
  }
  for(int i = 0; i < n; i++) {
    b[i] = d[i];
  }

  // for(int i = 0; i < n; i++) {
  //   b[i] = b[c[i]-1];
  // }
  int ans = 0;



  map<int, int> f0, f1;
  for(int x : a) {
    f0[x]++;
  }
  for(int x : b) {
    f1[x]++;
  }
  for(auto it : f0) {
    int x = it.second;
    int y = f1[it.first];
    ans += x*y;
  }
  cout<<ans<<'\n';
}

