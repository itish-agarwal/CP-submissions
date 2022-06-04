#include <bits/stdc++.h>

using namespace std;

bool is_substring(string t, string s) {
  int m = t.size(), n = s.size();
  for(int i = 0; i <= n - m; ++i) {
    if(s.substr(i, m) == t) {
      return true;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;
  vector<string> S(N);

  for(auto& s : S)
    cin >> s;

  int ans = 0;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; ++j) {
      if(i!=j) {
        if(is_substring(S[j], S[i])) {
          bool ok = 1;
          for(int k = 0; k < N; k++) {
            if(k!=i && k!=j) {
              if(is_substring(S[j], S[k]) && is_substring(S[k], S[i])) {
                ok = 0;
                break;
              }
            }
          }
          ans += ok;
        }
      }
    }
  }
  cout << ans << '\n';
}