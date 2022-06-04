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
    vector<int> done(26);
    for(char ch : s) {
      int x = ch - 'a';
      if(!done[x]) {
        cout << ch;
      }
      done[x] = 1;
    }
    cout << '\n';
  }
}