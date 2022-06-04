#include <bits/stdc++.h>
 
using namespace std;
using namespace chrono;
 
void test_case() {
   int N, M;
   cin >> N >> M;
 
   vector<int> A(N);
   for (auto &a : A)
      cin >> a;
 
   sort(A.begin(), A.end());
 
   int64_t sum = N;
   for (int i = 0; i < N; ++i)
      sum += max (A[i], A[(i + 1) % N]);
 
   if (sum <= M)
      cout << "YES" << '\n';
   else
      cout << "NO" << '\n';
}
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
 
   int tests = 1;
   cin >> tests;
 
   while(tests--)
      test_case();
}