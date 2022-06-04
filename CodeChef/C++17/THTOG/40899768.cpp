#include <bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];   
  }
  for(int i = 0; i < n; i++) {
    vector<int> ans;
    multiset<int> s;
    for(int j = 0; j < n; j++) {
      if(i!=j) {
        s.insert(a[j]);
      }
    }
    int last = a[i];
    bool ok = 1;
    ans.push_back(last);
    for(int i = 1; i < n; i++) {
      if(last%3==0 && s.find(last/3)!=s.end()) {
        s.erase(s.find(last/3));
        ans.push_back(last/3);
        last /= 3;
      } else if(s.find(2*last)!=s.end()) {
        s.erase(s.find(2*last));
        ans.push_back(2*last);
        last *= 2;
      } else {
        ok = 0;
        break;
      }
    }
    if(ok) {
      for(int x : ans) {
        cout << x << " ";
      }
      return 0;
    }
  }
}
