#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string ans = "";
  for(int i = 0; i < 26; ++i) {
    int x;
    cin >> x;
    ans.push_back(x - 1 + 'a');
  }

  cout << ans << '\n';
}