#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int N;
    cin >> N;
    long long ans = 0;
    auto consider = [&](int B, int C) {
      ans += (N - C) / B;
    };
    for(int B = 1; B <= N; ++B) {
      for(int C = 1; C * C <= B; ++C) {
        if(B % C == 0) {
          int d = B / C;
          consider(B, C);
          if(C * C != B) {
            consider(B, B/C);
          }
        }
      }
    }
    cout << ans << '\n';
  }
}