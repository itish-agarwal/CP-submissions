#include <bits/stdc++.h>

using namespace std;
#define int long long
int X, Y, A, B, N, M;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while(tt--) {    
    cin >> X >> Y >> A >> B >> N >> M;
    int ans = 0;
    for(int a = 0; a <= A; a++) {
      //a is number of items of gold that we take in first bag
      if(a*N <= X) {
        int mxB = (X - a*N)/M;
        if(mxB >= B) {
          //first bag can take all of B items
          int leftA = A - a;
          int cntA = Y / N;
          cntA = min(leftA, cntA);
          ans = max(ans, a + B + cntA);
        } else {
          int leftA = A - a;
          int leftB = B - mxB;
          if(N < M) {
            //a has less weight;
            int cntA = Y / N;
            cntA = min(leftA, cntA);
            int weight_left = Y - cntA*N;
            int cntB = weight_left / M;
            cntB = min(leftB, cntB);
            ans = max(ans, a + mxB + cntA + cntB);
          } else {
            //b has less weight;
            int cntB = Y / M;
            cntB = min(leftB, cntB);
            int weight_left = Y - cntB*M;
            int cntA = weight_left / N;
            cntA = min(leftA, cntA);
            ans = max(ans, a + mxB + cntA + cntB);
          }
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
