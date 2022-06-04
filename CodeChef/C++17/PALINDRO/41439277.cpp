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
    string s;
    cin >> s;
    vector<int> cnt(26);
    for(char ch : s) {
      cnt[ch-'a']++;
    }
    int odd = 0;
    for(int x : cnt) {
      odd += x%2;
    }
    if(odd >= 1) --odd;
    cout << odd << '\n';
  }
  return 0;
}
