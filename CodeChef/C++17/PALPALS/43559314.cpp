#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    string s;
    cin >> s;
    vector<int> cnt(26);
    for(char c : s) {
      cnt[c - 'a']++;
    }
    int odd = 0, even = 0;
    for(int c : cnt) {
      if(c & 1) odd++;
      even += c / 2;
    }
    (even >= odd ? puts("YES") : puts("NO"));
  }
}
