#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  string S;
  cin >> N >> S;
  int bad = 0;
  for(int i = 0; i < N; ++i) {
    if(S[i] == '1') {
      bad = i;
      break;
    }
  }
  cout << (bad % 2 == 0 ? "Takahashi" : "Aoki") << '\n';
}