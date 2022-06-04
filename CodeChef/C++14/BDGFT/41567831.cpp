#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> pre(n);
    pre[0] = (s[0]=='1');
    for(int i = 1; i < n; i++) {
      if(s[i]=='1') pre[i] = pre[i-1] + 1;
      else pre[i] = pre[i-1];
    }
    long long answer = 0;
    for(int y = 1; y + y*y <= n; y++) {
      int l = y + y*y;
      for(int i = 0; i <= n-l; i++) {
        int cnt1 = pre[i+l-1] - (i>0 ? pre[i-1] : 0);
        answer += (cnt1==y);
      }
    }
    cout << answer << '\n';
  }
  return 0;
}
