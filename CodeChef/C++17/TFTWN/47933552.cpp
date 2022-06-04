#include <bits/stdc++.h>

using namespace std;
#define int long long 

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, Q;
  cin >> N >> Q;

  vector<int> chefs(N);

  for(auto& chef : chefs)
    cin >> chef;

  const int INF = 2e18 + 7;
  int lo = 1, hi = INF, ans = hi;

  auto check = [&](int tt) {
    int dishes = 0;
    for(auto chef : chefs) 
      dishes += tt / chef;
    return dishes >= Q;
  };

  while(lo <= hi) {
    int mid = (lo + hi) / 2;
    if(check(mid)) {
      ans = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }

  cout << (ans % 3 ? "GOOD EXPERIENCE" : "BAD EXPERIENCE") << '\n';
}