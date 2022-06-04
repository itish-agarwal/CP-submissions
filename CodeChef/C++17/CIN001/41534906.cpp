#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    ll a, b, c, r;
    cin >> a >> b >> c >> r;
    ll start = min(a, b);
    ll end = max(a, b);
    ll from = c - r;
    ll to = c + r;
    if(from >= start) {
      if(from >= end) {
        cout << end-start << ' ';
      } else {
        if(to <= end) {
          cout << end-start-to+from << ' ';
        } else {
          cout << from-start << ' ';
        }
      }
    } else {
      if(start >= to) {
        cout << end-start << ' ';
      } else {
        if(end <= to) {
          cout << "0 ";
        } else {
          cout << end-to << ' ';
        }
      }
    }
  }
  return 0;
}
