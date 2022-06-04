#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tests;
  cin >> tests;

  while(tests--) {
    string S;
    cin >> S;

    int N = S.size();

    vector<int> A, I, J;

    for(int i = 0; i < N; i++) {
      if(S[i] == 'A')
        A.emplace_back(i);
      else if(S[i] == 'I') 
        I.emplace_back(i);
      else if(S[i] == 'J')
        J.emplace_back(i);
    }

    int ans = 2 * N;

    auto update = [&](vector<int>& a, vector<int>& b, vector<int>& c) {
      for(int i : a) {
        int lb = upper_bound(b.begin(), b.end(), i + 1) - b.begin();
        if(lb >= 0 && lb < (int)b.size()) {
          int j = b[lb];
          lb = upper_bound(c.begin(), c.end(), j + 1) - c.begin();
          if(lb >= 0 && lb < (int)c.size()) {
            ans = min(ans, c[lb] - i);
          }
        }
      }
    };

    update(A, I, J);
    update(A, J, I);
    update(I, A, J);
    update(I, J, A);
    update(J, I, A);
    update(J, A, I);

    cout << (ans >= 2 * N ? -1 : ans) << '\n';
  }
  return 0;

}