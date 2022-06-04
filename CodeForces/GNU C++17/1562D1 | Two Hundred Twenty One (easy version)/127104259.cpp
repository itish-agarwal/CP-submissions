#include <bits/stdc++.h>
 
using namespace std;
 
void test_case() {
  int N, Q;
  cin >> N >> Q;
 
  string S;
  cin >> S;
 
  string good0 = "", good1 = "";
  for(int i = 0; i < N; ++i) {
    good0.push_back(i % 2 ? '-' : '+');
    good1.push_back(i % 2 ? '+' : '-');
  }
 
  vector<int> preffix_match0(N), preffix_match1(N);
  preffix_match0[0] = (S[0] == good0[0]);
  preffix_match1[0] = (S[0] == good1[0]);
 
  for(int i = 1; i < N; ++i) {
    preffix_match0[i] = preffix_match0[i-1] + (S[i] == good0[i]);
    preffix_match1[i] = preffix_match1[i-1] + (S[i] == good1[i]);
  }
 
  for(int q = 0; q < Q; ++q) {
    int l, r;
    cin >> l >> r;
    --l, --r;
    if(r % 2 == l % 2) {
      cout << 1 << '\n';
    }
 
    else {
      int match = 0;
      if(l % 2) {
        match = preffix_match1[r] - (l > 0 ? preffix_match1[l-1] : 0);
      }
 
      else {
        match = preffix_match0[r] - (l > 0 ? preffix_match0[l-1] : 0);
      }
      cout << (2 * match == r - l + 1 ? 0 : 2) << '\n';
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int T;
  cin >> T;
  while(T--) 
    test_case();
}