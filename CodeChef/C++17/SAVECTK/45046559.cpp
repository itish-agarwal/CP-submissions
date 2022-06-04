#include <bits/stdc++.h>

using namespace std;
#define int long long 

int f(vector<int> a) {
  int n = a.size();
  int mid = a[n/2];
  int ans = 0;
  for(int x : a) {
    ans += abs(mid - x);
  }
  int pos = 0;
  if(n%2 == 0) {
    int m = a[n/2 - 1];
    for(int x : a) {
      pos += abs(m - x);
    }
    ans = min(ans, pos);
  }
  return ans;
}
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
    vector<int> b;
    for(int i = 1; i < n; i++) {
      b.push_back(a[i]);
    }
    int one = f(b);
    b.clear();
    for(int i = 0; i + 1 < n; i++) {
      b.push_back(a[i]);
    }
    int two = f(b);
    if(one <= two) {
      cout << a[0] << " " << one << '\n';
    } else {
      cout << a.back() << " " << two << '\n';
    }
  }
}
  