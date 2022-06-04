#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int N, P;
    cin >> N >> P;
    int answer = 0;
    for(int a = 1; a <= N; a++) {
      if(__gcd(a, P) == 1) {
        ++answer;
      }
    }
    long long res = (long long)answer*(long long)(answer-1)/2;
    cout << res << ' ';
  }
  return 0;
}
