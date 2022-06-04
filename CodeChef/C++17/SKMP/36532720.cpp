#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s, p;
  cin >> s >> p;
  vector<int> cnt(26, 0);
  for(char ch : s) {
    cnt[ch-'a']++;
  }
  for(char ch : p) {
    cnt[ch-'a']--;
  }
  string before = "", after = "";
  for(int i = 0; i < (p[0]-'a'); i++) {
    char ch = i + 'a';
    for(int j = 0; j < cnt[i]; j++) {
      before.push_back(ch);
    }
  }
  for(int i = (p[0]-'a'+1); i < 26; i++) {
    char ch = i + 'a';
    for(int j = 0; j < cnt[i]; j++) {
      after.push_back(ch);
    }
  }
  string all = "";
  for(int j = 0; j < cnt[p[0]-'a']; j++) {
    all.push_back(p[0]);
  }
  string ans = min(before + all + p + after, before + p + all + after);
  cout << ans << '\n';
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    solve();
  }
}
    
