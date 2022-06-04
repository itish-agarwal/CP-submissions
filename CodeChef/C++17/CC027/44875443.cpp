#include <bits/stdc++.h>

using namespace std;
#define int long long 

const int N = 1e5 + 10;
int PS[N], A[N];

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = "l" + s;
    memset(PS, 0, sizeof(PS));
    memset(A, 0, sizeof(A));
    for (int i = 1; i <= n; i++) {
      if (s[i] == 'l') PS[i] = 1;
    }
    for (int i = 1; i <= n; i++) PS[i] += PS[i - 1];
    auto getNext = [&](int idx, int T, int m = 1){
      if(T < 0)return -1LL;
      int mx = min(n,(idx + T / m));
      int l = mx, r = n, answer = mx;
      while(l <= r) {
        int mid = (l + r) >> 1;
        if(PS[mid] == PS[mx]) {
          answer = mid;
          l = mid + 1;
        }
        else r = mid - 1;
      }
      return answer;
    };
   
    auto ok = [&](int T){
      int prv = 0;
      for(int i = 1; i <= n; i++) if(s[i] == 'l'){
        prv = i-1;
        break;
      }
      for(int i = 1; i<= n; i++){
        if(s[i] != 'p')continue;
        prv = min(prv, i - 1);
        if(i - prv - 1 > T)return false;
        prv = max(getNext(i, T - 2 * (i - prv - 1)), getNext(i, T - (i - prv - 1), 2));
      }
      return prv == n;
    };
   
    int l = 0, r = 2e5+10, answer = -1;
    while(l <= r){
      int mid = (l + r) >> 1;
      if(ok(mid)){
        answer = mid;
        r = mid - 1;
      }
      else l = mid + 1;
    }
    cout << answer << "\n";
  }
}