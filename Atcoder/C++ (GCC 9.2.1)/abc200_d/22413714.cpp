#include <bits/stdc++.h>

using namespace std;
const int mod = 200;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] %= mod;
  }

  n = min(n, 20);

  vector<vector<int>> freq(mod + 1);

  for(int mask = 1; mask < (1 << n); mask++) {

    int s = 0;
    for(int i = 0; i < n; i++) {
      if(mask & (1 << i)) {
        s += a[i];
        s %= mod;
      }
    }
    freq[s].push_back(mask);
  }

  for(int rem = 0; rem < mod; rem++) {
    if(freq[rem].size() > 1) {
      cout << "Yes\n";

      vector<int> B, C;
      int m0 = freq[rem][0], m1 = freq[rem][1];

      for(int i = 0; i < n; i++) {
        if(m0 & (1 << i)) {
          B.push_back(i + 1);
        }
        if(m1 & (1 << i)) {
          C.push_back(i + 1);
        }
      }
      cout << (int)B.size() << " ";
      for(int ii : B) {
        cout << ii << " " ;
      }
      cout << '\n';
      cout << (int)C.size() << " ";
      for(int ii : C) {
        cout << ii << " ";
      }
      cout << '\n';
      return 0;
    }
  }
  cout << "No\n";
}