#include <bits/stdc++.h>
 
using namespace std;
#define int long long 
 
//Usage -> vector<int> a, cout << a << '\n'
ostream& operator << (ostream& stream, const vector<int>& v) {
  for(auto x : v) stream << x << " ";
  return stream;
}
int p1 = 1e9 + 7;
int p2 = 1400305337;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<tuple<int, int, int, int>> operations;
    int k = 0;
    for(int i =1 ; i < n; i++) {
      if(__gcd(a[i], a[i - 1]) > 1) {
        int mn = min(a[i - 1], a[i]);
        a[i] = mn;
        int y;
        if(k % 2) {
          y = p1;
        } else {
          y = p2;
        }
        k += 1;
        a[i - 1] = y;
        operations.emplace_back(i - 1, i, y, mn);
      }
    }
    cout << (int)operations.size() << '\n';
    for(auto it : operations) {
      cout << get<0>(it) + 1 << " " << get<1>(it) + 1 << " " << get<2>(it) << " " << get<3>(it) << '\n';
    }
  }
}