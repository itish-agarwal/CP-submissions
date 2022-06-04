#include <bits/stdc++.h>
 
using namespace std;
 
#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << ": "; pr(x); cout << "]\n";
#else
#define debug(x...)
#endif
 
void pr(string x)  { cout << '\"' << x << '\"'; }
void pr(long long x)  { cout << x; }
void pr(bool x)  { cout << x; }
void pr(int x)  { cout << x; }
 
template <class T, class V> void pr(const map<T, V>& mp);
template <class T, class... V> void pr(T t, V... v);
template <class T> void pr(const multiset<T>& pq);
template <class T> void pr(const vector<T>& v);
 
template <class T, class V> void pr(const map<T, V>& mp) {
   for (auto it = mp.begin(); it != mp.end(); ++it) { pr(*it); cout << " "; }
}
template <class T> void pr(const multiset<T>& pq) {
   vector<T> values(pq.begin(), pq.end()); pr(values);
}
template <class T> void pr(const vector<T>& v) {
   for (int i = 0; i < (int) v.size(); ++i) { pr(v[i]); cout << (i + 1 < (int) v.size() ? " " : ""); }
}
template <class T, class... V> void pr(T t, V... v) {
   pr(t); if(sizeof...(v)) cout << " | "; pr(v...);
}
//Global space begins
 
void test_case() {
   int N, M;
   cin >> N >> M;
 
   vector<string> grid(N);
   for (auto &row : grid)
      cin >> row;
 
   vector<pair<int, int>> robots;
   for (int i = 0; i < N; ++i)
      for (int j = 0; j < M; ++j)
         if (grid[i][j] == 'R')
            robots.emplace_back (i, j);
 
   auto allow = [&] (int x, int y) {
      return x >= 0 && x < N && y >= 0 && y < M;
   };
 
   for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
         if (grid[i][j] == 'R') {
            bool ok = true;
            int up = i, left = j;
            for (auto d : robots) {
               if (!allow (d.first - up, d.second) || !allow (d.first, d.second - left)) {
                  ok = false;
               }
            }
            if (ok) {
               cout << "YES" << '\n';
               return;
            }
         }
      }
   }
 
   cout << "NO" << '\n';
}
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
 
   int tt = 1;
   cin >> tt;
 
   while(tt--)
      test_case();
}