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
const int mod = 998244353;

void add_self(int& a, int b) {
   a += b;
   if(a >= mod) {
      a -= mod;
   }
}

int main() {
   int N, M, K;
   cin >> N >> M >> K;

   vector<vector<int>> dp (N + 1, vector<int> (M + 1, 0));
   vector<vector<int>> preffix_sums (N + 1, vector<int> (M + 1));

   for (int j = 1; j <= M; ++j)
      dp[N-1][j] = 1;

   for (int j = 1; j <= M; ++j)
      preffix_sums[N-1][j] = preffix_sums[N-1][j-1] + 1;

   for (int i = N - 2; i >= 0; --i) {
      for (int j = 1; j <= M; ++j) {

         int L = j + K, R = M;
         if (R >= L)
            add_self (dp[i][j], (preffix_sums[i+1][R] - (L > 0 ? preffix_sums[i+1][L-1] : 0) + mod) % mod);

         L = 1, R = j - K - (K == 0);
         if (R >= L)
            add_self (dp[i][j], (preffix_sums[i+1][R] - (L > 0 ? preffix_sums[i+1][L-1] : 0) + mod) % mod);
      }

      for (int j = 1; j <= M; ++j)
         preffix_sums[i][j] = (preffix_sums[i][j-1] + dp[i][j]) % mod;
   }

   // for (int i = 0; i < N; ++i)
   //    for (int j = 1; j <= M; ++j)
   //       cout << i << " " << j << " " << dp[i][j] << endl;

   int ans = 0;
   for (int j = 1; j <= M; ++j)
      add_self (ans, dp[0][j]);

   cout << ans << '\n';
}