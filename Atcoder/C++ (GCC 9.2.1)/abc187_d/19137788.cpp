#include <bits/stdc++.h>

using namespace std;
#define int int64_t

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  priority_queue<pair<int, pair<int, int>>> s;
  int a = 0, t = 0, ans = 0;    
  for(int i = 0; i < n; i++) {
    int A, B;
    cin >> A >> B;
    a += A;
    s.push({A+B+A, {A, B}});
  }
  while(a >= t) {
    t += (s.top().first - s.top().second.first);
    a -= s.top().second.first;
    ++ans;
    s.pop();
  }
  cout << ans << '\n';
  return 0;
}
