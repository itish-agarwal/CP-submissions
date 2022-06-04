#include <bits/stdc++.h>

using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  int st = -1, en = n;
  for(int i = 0; i < n; i++) {
    if(a[i] == i) {
      st = i;
    } else {
      break;
    }
  }
  for(int i = n-1; i >= 0; i--) {
    if(a[i] == i) {
      en = i;
    } else {
      break;
    }
  }
  int s = st + 1, e = en - 1;
  vector<int> b;
  for(int i = s; i <= e; i++) {
    b.push_back(a[i]);
  }
  reverse(b.begin(), b.end());
  for(int i = s; i <= e; i++) {
    a[i] = b[i-s];
  }
  bool ok = 1;
  for(int i = 0; i < n; i++) {
    if(a[i]!=i) {
      ok = 0; 
      break;
    }
  }
  if(ok) {
    if(s+1>=1 && s+1<=n && e+1>=1 && e+1<=n && e>s) {
      cout << s+1 << " " << e+1 << '\n';
    } else {
      cout << "0 0\n";
    }
  } else {
    cout << "0 0\n";
  }
  return 0;
}
