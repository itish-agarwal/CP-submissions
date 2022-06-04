#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;

  vector<pair<string, string>> names;
  for(int i = 0; i < N; ++i) {
    string s, t;
    cin >> s >> t;
    names.emplace_back(s, t);
  }

  for(int i = 0; i < N; ++i) {
    for(int j = i + 1; j < N; ++j) {
      if(names[i] == names[j]) {
        cout << "Yes" << '\n';
        return 0;
      }
    }
  }

  cout << "No" << '\n';
}