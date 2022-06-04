#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while(T--) {
    int N, K;
    cin >> N >> K;
    int value = (1 << N) - 1, len = (1 << N);
    cout << (long long)value * 2 * min(len / 2, K) << '\n';
    //2^N * min()
  }
}