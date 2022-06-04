#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    int N;
    cin >> N;
    vector<string> S(N);
    for(auto& s : S)
      cin >> s;

    auto beg_language1 = [&](string word) {
      for(char ch : word) {
        if(!(ch >= 'a' && ch <= 'm')) {
          return 0;
        }
      }
      return 1;
    };

    auto beg_language2 = [&](string word) {
      for(char ch : word) {
        if(!(ch >= 'N' && ch <= 'Z')) {
          return 0;
        }
      }
      return 1;
    };

    bool ok = 1;
    for(auto s : S) {
      if(!beg_language1(s) && !beg_language2(s)) {
        ok = 0;
        break;
      }
    }

    cout << (ok ? "YES\n" : "NO\n");
  }
}