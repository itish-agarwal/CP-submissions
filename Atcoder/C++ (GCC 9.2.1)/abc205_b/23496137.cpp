#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> cnt(N);
  for(int i = 0; i < N; i++) {
    int a;
    cin >> a;
    cnt[--a]++;
  }
  bool ok = true;
  for(int i = 0; i < N; i++) {
    if(cnt[i] != 1) 
      ok = false;
  }
  cout << (ok ? "Yes" : "No") << '\n';
  return 0;
}