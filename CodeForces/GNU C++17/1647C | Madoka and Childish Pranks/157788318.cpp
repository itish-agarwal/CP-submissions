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
 
   vector<string> make;
   for (int i = 0; i < N; ++i)
      make.push_back (string (M, '0'));
 
   vector<array<int, 4>> operations;
 
   for (int i = 0; i < N; ++i) 
      for (int j = M - 1; j >= 1; --j)
         if (grid[i][j] == '1') {
            operations.push_back ({i, j - 1, i, j});
            make[i][j] = '1';
         }
 
   for (int i = N - 1, j = 0; i >= 0; --i) {
      if (grid[i][0] == '1') {
         if (i == 0) {
            cout << -1 << '\n';
            return;
         }
         make[i-1][j] = '0';
         make[i][j] = '1';
         operations.push_back ({i - 1, j, i, j});
      }
   }
 
   if (make != grid) {
      cout << -1 << '\n';
      return;
   }
 
   cout << operations.size() << '\n';
   for (auto arr : operations)
      cout << arr[0] + 1 << " " << arr[1] + 1 << " " << arr[2] + 1 << " " << arr[3] + 1 << '\n';
}
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
 
   int tests = 1;
   cin >> tests;
 
   while(tests--)
      test_case();
}