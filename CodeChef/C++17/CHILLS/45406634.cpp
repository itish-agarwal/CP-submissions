#include <bits/stdc++.h>

using namespace std;
#define int long long 

const int nax = 1e5 + 7;
const int INF = 2e18 + 7;
int n, k, a[nax], pref[nax];

int f(int in) {
  int R = a[in];
  int L = R - k + 1;
  int ans = INF;
  while(L <= a[in]) {
    int mid = L + k / 2 - (k%2 == 0);
    // cout << mid << endl;
    int candidate = 0;
    int li = upper_bound(a, a + n, mid) - a - 1;
    if(li >= 0 && li < n) {
      int s = pref[li];
      int add = R * (li + 1) - s;
      candidate += add;
    }

    li++;
    if(li >= 0 && li < n) {
      int s = pref[n-1] - (li>0 ? pref[li-1] : 0);
      int num = n - li;
      int add = s - num * L;
      candidate += add;
    }
    ans = min(ans, candidate);
    L++;
    R++;
  }
  return ans;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    pref[0] = a[0];
    for(int i = 1; i < n; i++) {
      pref[i] = pref[i-1] + a[i];
    }
    // cout << f(1) << endl;
    int ans = f(n / 2);
    // cout << ans << endl;
    if(n%2 == 0) {
      ans = min(ans, f(n / 2 - 1));
    }
    cout << ans << '\n';
  }
}