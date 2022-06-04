#include <bits/stdc++.h>
 
using namespace std;
using namespace chrono;
 
#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << ": "; pr(x); cout << "]\n";
#else
#define debug(x...)
#endif
 
void pr(string x)  { cout << '\"' << x << '\"'; }
void pr(char x)  { cout << '\'' << x << '\''; }
void pr(long long x)  { cout << x; }
void pr(double x)  { cout << x; }
void pr(bool x)  { cout << x; }
void pr(int x)  { cout << x; }
 
template <class T, class V> void pr(const pair<T, V> &x);
template <class T, class V> void pr(const map<T, V>& mp);
template <class T, class... V> void pr(T t, V... v);
template <class T> void pr(const multiset<T>& pq);
template <class T> void pr(const vector<T>& v);
template <class T> void pr(const set<T>& pq);
 
template <class T, class V> void pr(const pair<T, V>& x) {
   cout << "{"; pr(x.first); cout << ", "; pr(x.second); cout << "}";
}
template <class T, class V> void pr(const map<T, V>& mp) {
   for (auto it = mp.begin(); it != mp.end(); ++it) { pr(*it); cout << " "; }
}
template <class T> void pr(const multiset<T>& pq) {
   vector<T> values(pq.begin(), pq.end()); pr(values);
}
template <class T> void pr(const vector<T>& v) {
   for (int i = 0; i < (int) v.size(); ++i) { pr(v[i]); cout << (i + 1 < (int) v.size() ? " " : ""); }
}
template <class T> void pr(const set<T>& pq) {
   vector<T> values(pq.begin(), pq.end()); pr(values);
}
template <class T, class... V> void pr(T t, V... v) {
   pr(t); if(sizeof...(v)) cout << " | "; pr(v...);
}
//Global space begins
 
bool good (vector<vector<int>> a) {
   const int n = a.size();
   for (int i = 0; i < n; ++i)
      if (!is_sorted (a[i].begin(), a[i].end()))
         return false;
 
   return true;
}
 
void test_case() {
   int N, M;
   cin >> N >> M;
 
   vector<vector<int>> A(N, vector<int> (M));
   for (int i = 0; i < N; ++i)
      for (int j = 0; j < M; ++j)
         cin >> A[i][j];
 
   vector<vector<int>> S = A;
   for (auto &row : S)
      sort (row.begin(), row.end());
 
   vector<int> bad (M);
   for (int j = 0; j < M; ++j)
      for (int i = 0; i < N; ++i)
         if (A[i][j] != S[i][j])
            bad[j] = 1;
 
   int cnt = accumulate (bad.begin(), bad.end(), 0);
 
   if (cnt == 0) {
      cout << 1 << " " << 1 << '\n';
      return;
   }
 
   int x = -1, y = -1;
   for (int i = 0; i < M; ++i)
      if (bad[i]) {
         if (x == -1)
            x = i;
         else
            y = i;
      }
 
   if (x == -1 || y == -1) {
      cout << -1 << '\n';
      return;
   }
 
   vector<vector<int>> G = A;
   for (int i = 0; i < N; ++i)
      swap (G[i][x], G[i][y]);
 
   if (good (G))
      cout << x + 1 << " " << y + 1 << '\n';
   else
      cout << -1 << '\n';
 
}
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
 
   int tests = 1;
   cin >> tests;
 
   while(tests--)
      test_case();
}