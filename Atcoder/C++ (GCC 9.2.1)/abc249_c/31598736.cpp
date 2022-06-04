#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n, k;
   cin >> n >> k;
   vector<string> s(n);
   for (int i = 0; i < n; ++i) {
      cin >> s[i];
   }
   vector<vector<int>> is(n, vector<int> (26));
   for (int i = 0; i < n; ++i) {
      for (int j = 0; j < s[i].size(); ++j) {
         is[i][s[i][j] - 'a'] = 1;
      }
   }
   int ans = 0;
   for (int mask = 0; mask < 1 << n; ++mask) {
      vector<int> cnt(26);
      for (int i = 0; i < n; ++i) {
         if (mask >> i & 1) {
            for (int j = 0; j < 26; ++j) {
               if (is[i][j]) {
                  cnt[j] += 1;
               }
            }
         }
      }
      int pos = 0;
      for (int j = 0; j < 26; ++j) {
         pos += cnt[j] == k;
      }
      ans = max (ans, pos);
   }
   cout << ans << '\n';
}