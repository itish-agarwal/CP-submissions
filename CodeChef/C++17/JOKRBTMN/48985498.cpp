#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;

  while(T--) {
    int N, M, L;
    cin >> N >> M >> L;

    vector<int> belongs(N);

    for(int i = 0; i < M; ++i) {
      int K;
      cin >> K;
      for(int k = 0; k < K; ++k) {
        int C;
        cin >> C;
        belongs[C] = i;
      }
    }

    vector<int> strip(L);
    for(int i = 0; i < L; ++i)  {
      cin >> strip[i];
      strip[i] = belongs[strip[i]];
    }

    int ans = 0;

    for(int i = 0; i < L; ++i) 
      if(i == 0 || strip[i] != strip[i-1])
        ++ans;

    cout << ans << '\n';
  }
}
