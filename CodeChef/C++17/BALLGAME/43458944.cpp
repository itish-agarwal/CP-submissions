#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> ans;
  while(n--) {
    string s;
    cin >> s;
    if(s == "+") {
      int l = ans.size();
      ans.push_back(ans[l-1] + ans[l-2]);
    } else if(s == "X") {
      ans.pop_back();
    } else if(s == "Y") {
      ans.push_back(2*ans.back());
    } else {
      int x = stoi(s);
      ans.push_back(x);
    }
  }
  cout << accumulate(ans.begin(), ans.end(), 0) << '\n';
}
