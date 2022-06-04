#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int N;
  cin >> N;

  vector<int> A(N);
  for(auto& a : A)
    cin >> a;

  int MAX_N = *max_element(A.begin(), A.end());

  vector<bool> occur(MAX_N + 1);

  for(int a : A) {
    occur[a] = true;
  }

  int ans = 0;
  for(int i = 2; i <= MAX_N; i++) {
    if(occur[i]) {
      ans += 1;
      for(int j = i; j <= MAX_N; j += i) {
        occur[j] = false;
      }
    }
  }

  cout << ans << '\n';

}
