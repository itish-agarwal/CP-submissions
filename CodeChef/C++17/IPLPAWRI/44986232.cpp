#include <bits/stdc++.h>

using namespace std;
#define int long long 

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, a;
    cin >> n;
    map<int, int> mp;
    while(n--) {
      cin >> a;
      mp[a]++;
    }
    for(auto it : mp) {
      if(it.second == 3) {
        cout << 3*it.first << '\n';
        break;
      }
    }
  }
}