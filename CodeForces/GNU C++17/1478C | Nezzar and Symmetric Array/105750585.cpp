#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif
 
using namespace std;
#define int long long
 
void test_case() {
  int k;
  cin >> k;
  int n = k+k;
  vector<int> a(n);
  set<int> s;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    s.insert(a[i]);
  }
  bool ok = 1;
  sort(a.begin(), a.end());
  for(int i = 1; i < n; i += 2) {
    if(a[i]!=a[i-1]) {
      ok = 0;
      break;
    }
  }
  if(!ok || (int)s.size() != k) {
    cout << "NO\n";
    return;
  }
  vector<int> b;
  for(int x : s) b.push_back(x);
  sort(b.rbegin(), b.rend());
  if(b[0]%n) {
    cout << "NO\n";
    return;
  }
  vector<int> c;
  c.push_back(b[0] / n);
  int sub = 0;
  for(int i = 1; i < k; i++) {
    int sum = b[i];
    sub += 2*c[i-1];
    sum -= sub;
    int d = n - 2*i;
    if(sum%d) {
      cout << "NO\n";
      return;
    }
    c.push_back(sum / d);
  }
  sort(c.begin(), c.end());
  set<int> check;
  for(int x : c) {
    check.insert(x);
  }
  if((int)check.size()!=k || c[0] == 0) {
    cout << "NO\n";
  } else {
  
    for(int i = 0; i < k; i++) {
      c.push_back(-c[i]);
    }
    sort(c.begin(), c.end());
    int f = 0, l = 0;    
    vector<int> xx;
    for(int i = 0; i < n; i++) {
      int p = 0;
      p += l - (n-i+1)*c[i];
      p += (i+1)*c[i] - f;
      f += c[i];
      l -= c[i];
      xx.push_back(p);
    }
    sort(xx.begin(), xx.end());
    for(int i = 0; i < n; i++) {
      if(xx[i]!=a[i]) {
        cout << "NO\n";
        return;
      } 
    } 
    cout << "YES\n";
  }
}  
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    test_case();
  }
  return 0;
}