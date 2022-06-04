#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n, k;
   cin >> n >> k;
   string s;
   cin >> s;
   int ans = n;
   for (int b = 1; b <= n; ++b) {
      if (n % b == 0) {
         vector<vector<int>> freq (b, vector<int> (26));
         for (int j = 0; j < n; ++j) {
            freq[j % b][s[j] - 'a'] += 1;
         }  
         int ops = 0;
         for (int j = 0; j < b; ++j) {
            ops += accumulate (freq[j].begin(), freq[j].end(), 0) - *max_element (freq[j].begin(), freq[j].end());
         }
         if (ops <= k) {
            ans = min (ans, b);
         }
      }
   }  
   cout << ans << '\n';
}