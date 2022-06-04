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
    map<int, int> freq;
    for(int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      freq[a]++;
    }
    long long ans = ((long long)n * (n - 1))/2;
    for(auto it : freq) {
      long long f = it.second;
      ans -= (f * (f - 1))/2;
    }

    cout << 2 * ans << '\n';
  }
}