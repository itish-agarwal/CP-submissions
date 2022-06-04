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
    int st = 1;
    for(int i = 0; i < n; ++i) {
      if(i % 2) {
        int t = i + 1;
        int en = st + t - 1;
        for(int j = 1; j < t; ++j) {
          cout << en << "*";
          en--;
        }
        cout << en << '\n';
        st += t;
      } else {
        int t = i + 1;
        for(int j = 1; j < t; ++j) {
          cout << st << "*";
          st++;
        }
        cout << st << '\n';
        st++;
      }
    }
  }
}
    
