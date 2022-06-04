#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int a, b;
    cin >> a >> b;
    vector<int> x, y;
    while(a > 0) {
      x.push_back(a); 
      a /= 2;
    }
    while(b > 0) {
      y.push_back(b);
      b /= 2;
    }
    int xx = x.size(), yy = y.size();
    for(int i = 0; i < xx; ++i) {
      for(int j = 0; j < yy; j++) {
        if(x[i] == y[j]) {
          cout << i + j << '\n';
          goto done;
        }
      }
    }
    done: ;
  }
}
