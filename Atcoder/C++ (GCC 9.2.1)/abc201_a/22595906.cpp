#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<int> a(3);
  cin >> a[0] >> a[1] >> a[2];
  sort(a.begin(), a.end());
  if(a[2]-a[1]==a[1]-a[0]) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}