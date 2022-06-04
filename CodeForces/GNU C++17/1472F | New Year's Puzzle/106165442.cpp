#ifndef ONLINE_JUDGE
  #include "pch.h"
#else 
  #include <bits/stdc++.h>
#endif
 
using namespace std;
 
void test_case() {
  int n, m;
  cin >> n >> m;
  map<int, int> mp;
  set<int> s;
  for(int i = 0; i < m; i++) {
    int r, c;
    cin >> r >> c;
    s.insert(c);
    mp[c] += r;
  }
  vector<int> b{0};
  for(int x : s) {
    b.emplace_back(x);
  }
  b.emplace_back(n + 1);
  string x = "X", y = "X";
  for(int i = 1; i < (int)b.size(); i++) {
    int between = b[i] - b[i-1] - 1;
    if(between % 2) {
      x.push_back('.');
      y.push_back('.');
      if(mp[b[i]] == 1) {
        x += 'X';
        y += '.';
      } else if(mp[b[i]] == 2) {
        x += '.';
        y += 'X';
      } else {
        x += 'X';
        y += 'X';
      }
    } else {
      if(mp[b[i]] == 1) {
        x += 'X';
        y += '.';
      } else if(mp[b[i]] == 2) {
        x += '.';
        y += 'X';
      } else {
        x += 'X';
        y += 'X';
      }
    }
  }
  n = x.size();
  for(int i = 0; i < n; i++) {
    if(x[i]=='.' && y[i]=='.') {
      x[i] = y[i] = 'X';
    }
    if(x[i]=='.' && y[i]=='X') {
      if(i==n-1 || x[i+1]=='X') {
        puts("NO");
        return;
      }
      x[i] = x[i+1] = 'X';
    } else if(x[i]=='X' && y[i]=='.') {
      if(i==n-1 || y[i+1]=='X') {
        puts("NO");
        return;
      }
      y[i] = y[i+1] = 'X';
    }
  }
  puts("YES");
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    test_case();
  }
}