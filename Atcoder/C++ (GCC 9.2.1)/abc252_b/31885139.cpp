#include <bits/stdc++.h>

using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int n, k;
   cin >> n >> k;
   vector<int> a(n), b;
   for (int i = 0; i < n; ++i) {
      cin >> a[i];
      b.push_back(a[i]);
   }
   sort(b.begin(), b.end());
   for (int i = 0; i < k; ++i) {
      int x;
      cin >> x;
      x -= 1;
      if (a[x] == b.back()) {
         cout << "Yes" << endl;
         return 0;
      }
   }
   cout << "No" << endl;
}