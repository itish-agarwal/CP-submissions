#include <bits/stdc++.h>
 
using namespace std;
 
#ifndef ONLINE_JUDGE
#define debug(x) cout << "[" << #x << ": " << x << "]\n";
#else
#define debug(x)
#endif
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int tests;
  cin >> tests;
 
  while(tests--) {
    int N;
    cin >> N;
 
    debug(N);
    vector<int> A(N);
    for(auto& a : A) {
      cin >> a;
      a %= 2;
    }
 
    int sum = accumulate(A.begin(), A.end(), 0), odds = sum;
    sum = max(sum, N - sum);
 
    if(sum > (N + 1) / 2) {
      cout << -1 << '\n';
    }
 
    else {
 
      auto calculate = [&](int odd_index, int even_index) {
        long long res = 0;
        for(int i = 0; i < N; ++i) {
          if(A[i] % 2) {
            res += max(0, i - odd_index);
            odd_index += 2;
          }
 
          else {
            res += max(0, i - even_index);
            even_index += 2;
          }
        }
        return res;
      };
 
      long long ans;
 
      if(N % 2) {
        if(odds > N - odds) {
          ans = calculate(0, 1);
        }
        else {
          ans = calculate(1, 0);
        }
      }
 
      else {
        ans = min(calculate(0, 1), calculate(1, 0));
      }
      cout << ans << '\n';
    }
  }
}