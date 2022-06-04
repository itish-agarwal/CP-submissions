#include <bits/stdc++.h>

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
    int answer = 0;
    for(int i = 1; i < n; ++i) {
      if(a[i] < a[i - 1]) {
        answer += a[i - 1] - a[i];
        a[i] = a[i - 1];
      }
    }
    cout << answer << '\n';
  }
}