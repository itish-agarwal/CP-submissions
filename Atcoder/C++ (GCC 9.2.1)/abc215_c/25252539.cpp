#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string S;
  int K;
  cin >> S >> K;

  vector<string> all;
  sort(S.begin(), S.end());

  all.emplace_back(S);

  while(next_permutation(S.begin(), S.end())) 
    all.emplace_back(S);

  cout << all[--K] << '\n';
}