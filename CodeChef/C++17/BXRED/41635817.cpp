#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x;
  cin >> n;
  multiset<int> s;
  for(int i = 0; i < n; i++) {
    cin >> x;
    s.insert(x);
  }
  int answer = n;
  while(1) {
    int t = s.size();
    if(t <= 1) break;
    int large = *s.rbegin();
    s.erase(s.find(large));
    auto it = s.upper_bound(large/2);
    if(it==s.begin()) {
      
    } else {
      it--;
      answer--;
      s.erase(it);
    }
  }
  cout << answer << '\n';
  return 0;
}
