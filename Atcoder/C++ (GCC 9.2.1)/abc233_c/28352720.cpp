#include <bits/stdc++.h>

using namespace std;
vector<vector<int64_t>> A;
int64_t X;
int N;

int rec(int i, int64_t prod) {
   if (i == N) 
      return prod == X;

   int res = 0;
   for (auto &x : A[i]) 
      if (x <= X / prod) 
         res += rec(i + 1, prod * x);

   return res;
}
   
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin >> N >> X;
   for (int i = 0; i < N; ++i) {
      int L;
      cin >> L;
      vector<int64_t> back;
      for (int j = 0; j < L; ++j) {
         int64_t x;
         cin >> x;
         back.push_back(x);
      }
      A.push_back(back);
   }
   cout << rec(0, 1) << '\n';
}