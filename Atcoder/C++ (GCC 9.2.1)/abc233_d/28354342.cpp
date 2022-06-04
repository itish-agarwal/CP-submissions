#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int N;
   int64_t K;
   cin >> N >> K;
   map<int64_t, int> freq;
   freq[0]++;
   int64_t ans = 0, s = 0;
   for (int i = 0; i < N; ++i) {
      int x;
      cin >> x;
      s += x;
      ans += freq[s - K];
      freq[s]++;
   }
   cout << ans << '\n';
}