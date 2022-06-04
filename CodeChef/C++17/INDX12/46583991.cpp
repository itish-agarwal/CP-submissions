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
    int sum = 0;
    for(char c : s) {
      sum += c - 'a' + 1;
    }
    if(sum % 2) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}