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
    vector<int> s(n);
    for(int i = 0; i < n; ++i) {
      cin >> s[i];
    }
    long long answer = 0;
    for(int i = 1; i < n; ++i) {
      answer += max(s[i], s[i - 1]) - min(s[i], s[i - 1]) -1;
    }
    cout << answer << '\n';
  }
  return 0;
}
