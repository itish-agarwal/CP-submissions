#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> end(n), start(n);
  end[0] = a[0];
  for(int i = 1; i < n; i++) {
    end[i] = a[i] + max(0LL, end[i-1]);
  }
  start[n-1] = a[n-1];
  for(int i = n-2; i >= 0; i--) {
    start[i] = a[i] + max(0LL, start[i+1]);
  }
  int answer = a[0] + a[1];
  
  vector<int> pre(n), post(n);
  
  pre[0] = end[0];
  for(int i = 1; i < n; i++) {
    pre[i] = max(end[i], pre[i-1]);
  }
  post[n-1] = start[n-1];
  for(int i = n-2; i >= 0; i--) {
    post[i] = max(start[i], post[i+1]);
  }
  
  for(int i = 0; i+1 < n; i++) {
    int before = pre[i];
    int after = post[i+1];
    answer = max(answer, before + after);
  }
  cout << answer << '\n';
  return 0;
}
