#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n, a;
    int z = 0, o = 0;
    cin >> n;
    vector<int> b;
    for(int i = 0; i < n; i++) {
      cin >> a;
      if(a == 0) {
        z += 1;
      } else {
        if(a == 1) {
          o += 1;
        } else {
          b.push_back(a);
        }
      }
    }
    if(o == n - z) {
      cout << "1 1\n";
    } else {
      sort(b.begin(), b.end());
      cout << (int)b.size() << " " << b[0] << '\n';
    }
  }
}