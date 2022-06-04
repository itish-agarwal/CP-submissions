#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int n;
    cin >> n;
    int st = 0, t = 0;
    for(int i = -1; i < n/2; ++i) {
      st++;
      t++;
      for(int j = 1; j < t; ++j) {
        cout << st << "*";
      }
      cout << st;
      cout << '\n';
    }
    st--;
    t--;
    for(int i = 0; i < n/2; ++i) {
      for(int j = 1; j < t; ++j) {
        cout << st << "*";
      }
      cout << st;
      st--;
      t--;
      cout << '\n';
    }
  }
}
