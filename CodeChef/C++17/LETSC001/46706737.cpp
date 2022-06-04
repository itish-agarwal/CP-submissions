#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> is_prime(n+6, 1);

  for(int i = 2; i < n+6; i++) {
    if(is_prime[i]) {
      for(int j = i + i; j < n+6; j += i) {
        is_prime[j] = false;
      }
    }
  }

  int ans = 0;
  for(int i = 2; i <= n; i++) {
    if(is_prime[i]) {
      ans++;
    }
  }
  cout << ans << '\n';
}