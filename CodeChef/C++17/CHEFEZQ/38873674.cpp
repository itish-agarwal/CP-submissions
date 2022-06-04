#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int TT;
  cin >> TT;
  while(TT--) {
    int n, k;
    cin >> n >> k;
    bool done = false;
    vector<long long> a(n + 1);
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    long long passed = 0, s = 0, ans;
    for(int i = 1; i <= n; i++) {
      s += a[i];
      passed = s - i*k;
      //cout << passed << '\n';
      if(passed < 0) {
        cout << i << '\n';
        done = true;
        break;
      }
    }
    if(done <= 0) {
      ans = n;
      ans += passed/k;
      ++ans;
      cout << ans << '\n';
    }
  }
  return 0;
}
    
