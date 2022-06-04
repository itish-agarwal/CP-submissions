#include <bits/stdc++.h>
 
using namespace std;
#define int long long 
const int nax = 1e5 + 6;
int cnt[nax][2];

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  while(n--) {
    int x, p;
    cin >> x >> p;
    cnt[x][p]++;
  }
  int ans = 0;
  for(int i = 0; i < nax; ++i) {
    if(cnt[i][0] == cnt[i][1]) {
      ans += i * cnt[i][0];
    } else if(cnt[i][0] > cnt[i][1]) {
      ans -= i * cnt[i][0];
    } else {
      ans += i * cnt[i][1];
    }
  }
  cout << ans << '\n';
}
