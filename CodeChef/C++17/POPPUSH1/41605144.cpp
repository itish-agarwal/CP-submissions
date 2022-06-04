#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> cnt(1001);
  while(n--) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  int answer = 0;
  for(int x : cnt) {
    answer += x/2 + x%2;
  }
  cout << answer << '\n';
  return 0;
}
