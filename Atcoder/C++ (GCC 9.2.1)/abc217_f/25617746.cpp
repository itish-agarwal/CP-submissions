#include <bits/stdc++.h>

using namespace std;
using namespace chrono;
#define int long long

#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << ": "; pr(x); cout << "]\n";
#else
#define debug(x...)
#endif

void pr(string x)  { cout << '\"' << x << '\"'; }
void pr(char x)  { cout << '\'' << x << '\''; }
void pr(long double x)  { cout << x; }
void pr(long long x)  { cout << x; }
void pr(double x)  { cout << x; }
void pr(float x)  { cout << x; }
void pr(long x)  { cout << x; }
void pr(bool x)  { cout << x; }
// void pr(int x)  { cout << x; }

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
  for(auto it = mp.begin(); it != mp.end(); ++it) {
    pr(*it); auto copy = it;
    if(++copy != mp.end()) 
      cout << " ";
  }
}
template <class T> void pr(const multiset<T>& pq) {
  vector<T> values;
  for(auto& value : pq) 
    values.push_back(value);

  pr(values);
}
template <class T> void pr(const vector<T>& v) {
  for(int i = 0; i < (int) v.size(); ++i) {
    pr(v[i]); cout << (i + 1 < (int) v.size() ? " " : "");
  }
}
template <class T> void pr(const set<T>& pq) {
  vector<T> values;
  for(auto value : pq)
    values.push_back(value);

  pr(values);
}
template <class T, class... V> void pr(T t, V... v) {
  pr(t); if(sizeof...(v)) cout << " | ";
  pr(v...);
}
//Global space begins
const int mod = 998244353;
void add_self(int& a, int b) {
  a += b;
  if(a >= mod) {
    a -= mod;
  }
}

const int MAX_N = 205;
int fac[MAX_N];

template <class T>
T power(T a, T b) {
  T res = 1;
  while(b > 0) {
    if(b % 2)
      res = (res * a) % mod;

    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}

int nCr(int n, int r) {
  int p = fac[n];
  int q = ((long long) fac[r] * fac[n-r]) % mod;
  q = power<long long>(q, mod - 2);

  return ((long long) p * q) % mod;
}

void test_case() {
  int N, M;
  cin >> N >> M;

  N *= 2;

  vector<vector<int>> good_terms(N, vector<int> (N));
  vector<int> edges[N];

  for(int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    good_terms[a][b] = good_terms[b][a] = 1;
    edges[a].push_back(b);
  }

  vector<vector<int>> dp(N, vector<int> (N));
  for(int l = N - 1; l >= 0; --l) {
    for(int r = l + 1; r < N; r += 2) {
      if(r == l + 1) {
        dp[l][r] = good_terms[l][r];
        continue;
      }
      for(int x : edges[l]) {
        if(x <= r && (x - l - 1) % 2 == 0 && (x == r || (r - x) % 2 == 0)) {
          int n1 = (x - l - 1) / 2;
          int n2 = (r - x) / 2;
          int ways = nCr(n1 + n2 + 1, n2);
          int w1 = (l + 1 <= x - 1 ? dp[l + 1][x - 1] : 1);
          int w2 = (x + 1 <= r ? dp[x + 1][r] : 1);
          long long k = (((w1 * w2) % mod) * ways) % mod;
          add_self(dp[l][r], k);
        }
      }
    }
  }

  cout << dp[0][N - 1] << '\n';
} 

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  fac[0] = 1;
  for(int i = 1; i < MAX_N; ++i)
    fac[i] = ((long long)i * fac[i-1]) % mod;

  int tests = 1;
  // cin >> tests;
  while(tests--)
    test_case();

}