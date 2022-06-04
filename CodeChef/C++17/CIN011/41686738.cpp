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
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int answer = a[0];
    for(int i = 1; i < n; i++) {
      a[i] = a[i] + max(0, a[i-1]);
      answer = max(answer, a[i]);
    }
    cout << max(0, answer) << '\n';
  }
  return 0;
}
      
    

