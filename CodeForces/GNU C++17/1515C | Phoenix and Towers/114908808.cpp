#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int tt;
  cin >> tt;
  while(tt--) {
    int n, m, x;
    cin >> n >> m >> x;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a[i] = {x, i};
    }
    sort(a.begin(), a.end());
 
    vector<int> tower(n);
 
    for(int i = 0; i < m; i++) {
      tower[i] = i;
    }
 
    int j = 0;
    for(int i = n - 1; i >= m; i--) {
      tower[i] = j;
      j = (j + 1) % m;
    }
 
    vector<int> answer(n);
 
    for(int i = 0; i < n; i++) {
      int idx = a[i].second;
      int t = tower[i];
      answer[idx] = t;
    }
    cout << "YES\n";
    for(int ai : answer) {
      cout << ai + 1 << " ";
    }
    cout << '\n';
  }
}