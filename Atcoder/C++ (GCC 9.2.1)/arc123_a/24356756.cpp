#include <bits/stdc++.h>

using namespace std;
//Usage -> vector<int> a, cout << a << '\n'
ostream& operator << (ostream& stream, const vector<int>& v) {
  for(auto x : v) stream << x << " ";
  return stream;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i = 0; i < N; ++i) 
    cin >> A[i];
  vector<int> B(N);
  for(int i = 0; i < N; ++i)
    cin >> B[i];
  vector<int> C(N);
  for(int i = 0; i < N; ++i) 
    cin >> C[i];

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());

  int ans = 0, j = 0, k = 0;

  for(int i = 0; i < N; ++i) {
    int it = A[i];
    int in1 = upper_bound(B.begin() + j, B.end(), it) - B.begin();
    if(in1 < N) {
      int itt = B[in1];
      int in2 = upper_bound(C.begin() + k, C.end(), itt) - C.begin();
      if(in2 < N) {
        ++ans;
        j = in1 + 1;
        k = in2 + 1;
      }
      else {
        break;
      }
    } else {
      break;
    }
  }

  cout << ans << '\n';
  return 0;
}