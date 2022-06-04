#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  char x;
  int y;
  cin >> x >> y;

  int n = s.size();
  vector<int> in;
  for(int i = 0; i < n; i++) {
    if(s[i]==x) {
      in.push_back(i);
    }
  }

  int ans = 0;
  for(int i = 0; i + y - 1 < in.size(); i++) {
    int b = (i==0 ? in[i]+1 : in[i]-in[i-1]);
    int e = (i+y==in.size() ? n - in[i+y-1] : in[i+y]-in[i+y-1]);
    ans += b*e;
    // cout<<ans<<endl;
  }
  cout << ans << '\n';
}



