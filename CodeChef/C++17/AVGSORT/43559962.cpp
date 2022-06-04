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
    vector<int> a(n);
    for(auto& it : a) cin >> it;
    string ok = "No";
    for(int i = 1; i < n; ++i) {
      if(a[i] > a[i-1]) {
        ok = "Yes";
        break;
      }
    }
    cout << ok << '\n';
  }
}
