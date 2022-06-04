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
vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
 
void test_case() {
   int N, M;
   cin >> N >> M;
 
   vector<string> grid(N);
   for (auto &row : grid)
      cin >> row;
 
   vector<vector<int>> up (N, vector<int> (M));
   for (int i = 0; i < N; ++i) 
      for (int j = 0; j < M; ++j)
         up[i][j] = (grid[i][j] == '1') * ((i > 0 ? up[i-1][j] : 0) + 1);
 
   vector<vector<int>> down (N, vector<int> (M));
   for (int i = N - 1; i >= 0; --i)
      for (int j = 0; j < M; ++j)
         down[i][j] = (grid[i][j] == '1') * ((i + 1 < N ? down[i+1][j] : 0) + 1);
 
   vector<array<int, 4>> nice;
   for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
         if (grid[i][j] == '1') {
            int k = j;
            while (k + 1 < M && grid[i][k+1] == '1')
               k += 1;
 
            int val = up[i][j];
            for (int x = j; x <= k; ++x)
               if (up[i][x] != val) {
                  cout << "NO" << '\n';
                  return;
               }
 
            val = down[i][j];
            for (int x = j; x <= k; ++x)
               if (down[i][x] != val) {
                  cout << "NO" << '\n';
                  return;
               }
 
            j = k;
         }
      }
   }
 
   cout << "YES" << '\n';
}
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
 
   int tests = 1;
   cin >> tests;
 
   while(tests--)
      test_case();
}