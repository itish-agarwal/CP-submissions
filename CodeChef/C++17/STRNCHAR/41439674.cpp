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
    set<int> st;
    int n;
    cin >> n;
    while(n--) {
      char ch;
      cin >> ch;
      st.insert(ch);
    }
    bool ok = 1;
    for(char ch : s) {
      if(st.find(ch)==st.end()) {
        ok = 0;
        break;
      }
    }
    cout << ok << '\n';
  }
  return 0;
}
