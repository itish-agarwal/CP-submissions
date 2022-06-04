#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {
    string str;
    cin >> str;
    multiset<int> s;
    vector<int> cnt(26);
    for(char ch : str) {
      cnt[ch-'a']++;
    }
    int n = str.size();
    int X = 0;
    for(int y : cnt) {
      X += y/2;
    }
    cout << min(X, n/3) << '\n';
  }
  return 0;
}
