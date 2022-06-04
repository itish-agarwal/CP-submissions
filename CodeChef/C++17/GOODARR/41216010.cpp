#include <bits/stdc++.h>

using namespace std;

const int nax = 2e5 + 10;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> ans;
  for(int i = 1; i*i <= n; i++) {
    if(n%i == 0) {
      ans.push_back(i);
      if(i*i!=n) {
        ans.push_back(n/i);
      }
    }
  }
  cout << (int)ans.size() << '\n';
  for(int x : ans) {
    cout << x << " ";
  }
  cout << '\n';
  return 0;
}
