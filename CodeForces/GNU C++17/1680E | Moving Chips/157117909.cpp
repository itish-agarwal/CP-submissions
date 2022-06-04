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
   int N;
   cin >> N;
 
   vector<string> grid(2);
   cin >> grid[0] >> grid[1];
 
   int L = N, R = -1;
   for (int i = 0; i < N; ++i)
      if (grid[0][i] == '*' || grid[1][i] == '*') {
         L = min (L, i);
         R = max (R, i);
      }
 
   const int INF = 1e9 + 7;
   vector<vector<int>> dp(N, vector<int> (2, INF));
   
   for (int i = L; i <= R; ++i) 
      for (int j = 0; j < 2; ++j) {
         if (i == L) {
            dp[i][j] = grid[j^1][i] == '*';
            continue;
         } 
         for (int k = 0; k < 2; ++k) 
            dp[i][j] = min (dp[i][j], dp[i-1][k] + 1 + (grid[j^1][i] == '*' || j != k));
      }
 
   int ans = INF;
   for (int i = 0; i < N; ++i) 
      for (int j = 0; j < 2; ++j) 
         ans = min (ans, dp[i][j]);
   
   cout << min (dp[R][0], dp[R][1]) << '\n';
}
 
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
 
   int tt = 1;
   cin >> tt;
 
   while(tt--)
      test_case();
}