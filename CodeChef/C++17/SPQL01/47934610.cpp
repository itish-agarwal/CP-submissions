#include <bits/stdc++.h>

using namespace std;
#define int long long 

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tests;
  cin >> tests;
  while(tests--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> freq;
    for(int i = 0; i < n; i++) {
      cin >> a[i];
      freq[a[i]] += 1;
    }

    sort(a.begin(), a.end());
    int pairs = 0;

    int i = 0, j = n - 1, ans = 0;

    auto nc4 = [&](int n) {
      return (n * (n - 1) * (n - 2) * (n - 3)) / 24;
    };

    while(i < j) {
      int s = a[i] + a[j];
      if(s == k) {
        if(2 * a[i] == k) {
          ans += pairs * ((freq[a[i]] * (freq[a[i]] - 1)) / 2);
          ans += nc4(freq[a[i]]);
          break;
        } else {
          ans += pairs * freq[a[i]] * freq[a[j]];
          ans += ((freq[a[i]] * (freq[a[i]] - 1)) / 2) * ((freq[a[j]] * (freq[a[j]] - 1)) / 2); 
          pairs += freq[a[i]] * freq[a[j]];
          i += freq[a[i]];
          j -= freq[a[j]];
        }
      } else if(s > k) {
        j--;
      } else {
        i++;
      }
    }

    cout << ans << '\n';

  }
  return 0;
}