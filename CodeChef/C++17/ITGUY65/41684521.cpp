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
    int N = n;
    n = 2*n - 1;
    int ans[N][n];
    int sp = N-2;
    for(int i = N-1; i >= 0; i--) {
      int st = 1;
      for(int j = 0; j <= sp; j++) {
        cout << " ";
      }
      for(int j = st; j <= N-i; j++) {
        cout << st << " " ;
        st++;
      }
      for(int j = 0; j <= sp; j++) {
        cout << " ";
      }
      sp--;
      cout << '\n';
    }
  }
  return 0;
}
