#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << ": "; pr(x); cout << "]\n";
#else
#define debug(x...)
#endif
#define int long long

void pr(string x)  { cout << '\"' << x << '\"'; }
void pr(char x)  { cout << '\'' << x << '\''; }
void pr(long long x)  { cout << x; }
void pr(double x)  { cout << x; }
void pr(bool x)  { cout << x; }

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
const int ALPHABET = 26;
const int mod = 998244353;
const int nax = 1e5 + 7;
int fac[nax], C[5005][5005];

void add_self(int &a, int b) {
   a += b;
   if (a >= mod) {
      a -= mod;
   }
}

int power(int a, int b) {
   if(b == 0) 
      return 1;
 
   int res = power(a, b / 2);
   res = (res * res) % mod;
   if(b % 2) 
      res = (res * a) % mod;
 
   return res;
}

void test_case() {
   string S;
   cin >> S;
   const int N = S.size();
   vector<int> freq(ALPHABET);
   for (char ch : S)
      freq[ch-'a'] += 1;

   vector<vector<int>> dp(ALPHABET + 1, vector<int> (N + 1));
   dp[0][0] = 1;

   for (int a = 1; a <= ALPHABET; ++a) {
      for (int j = 0; j <= N; ++j) {
         for (int k = 0; k <= min(j, freq[a-1]); ++k) {
            int val = dp[a-1][j-k] * C[j][k];
            add_self(dp[a][j], val % mod);
         }
      }
   }

   int ans = 0;
   for (int j = 1; j <= N; ++j)
      add_self(ans, dp[ALPHABET][j]);

   cout << ans << '\n';
}

signed main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   fac[0] = 1;
   for (int x = 1; x < nax; ++x)
      fac[x] = (x * fac[x-1]) % mod;

   for (int n = 0; n < 5005; ++n) {
      for (int r = 0; r <= n; ++r) {
         if (r == 0 || r == n || n == 0) {
            C[n][r] = 1;
            continue;
         }
         C[n][r] = (C[n-1][r] + C[n-1][r-1]) % mod;
      }
   }

   int tests = 1;
   // cin >> tests;

   while(tests--)
      test_case();
}