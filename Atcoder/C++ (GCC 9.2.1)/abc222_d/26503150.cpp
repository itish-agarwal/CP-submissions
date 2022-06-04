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
void pr(long double x)  { cout << x; }
void pr(long long x)  { cout << x; }
void pr(double x)  { cout << x; }
void pr(float x)  { cout << x; }
void pr(long x)  { cout << x; }
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
  for(auto it = mp.begin(); it != mp.end(); ++it) { pr(*it); cout << " "; }
}
template <class T> void pr(const multiset<T>& pq) {
  vector<T> values(pq.begin(), pq.end()); pr(values);
}
template <class T> void pr(const vector<T>& v) {
  for(int i = 0; i < (int) v.size(); ++i) { pr(v[i]); cout << (i + 1 < (int) v.size() ? " " : ""); }
}
template <class T> void pr(const set<T>& pq) {
  vector<T> values(pq.begin(), pq.end()); pr(values);
}
template <class T, class... V> void pr(T t, V... v) {
  pr(t); if(sizeof...(v)) cout << " | ";
  pr(v...);
}
//Global space begins
const int mod = 998244353;
const int nax = 3e3 + 7;

void add_self(int& a, int b) {
  a += b;
  if(a >= mod) {
    a -= mod;
  }
}

void test_case() {
  int N;
  cin >> N;

  vector<int> A(N), B(N);
  for(auto &a : A)
    cin >> a;

  for(auto &b : B)
    cin >> b;

  vector<vector<int>> preffix_sums(N + 1, vector<int> (nax));
  vector<vector<int>> dp(N + 1, vector<int> (nax));

  for(int i = N; i >= 0; --i) {
    for(int j = 0; j < nax; ++j) {
      if(i == N) {
        dp[i][j] = (j >= A.back() && j <= B.back());
      }
      else {
        int L = max(A[i], j), R = B[i];
        dp[i][j] = (preffix_sums[i + 1][R] - (L > 0 ? preffix_sums[i + 1][L - 1] : 0) + mod) % mod;
      }
      preffix_sums[i][j] = dp[i][j];
    }
    for(int j = 1; j < nax; ++j) {
      add_self(preffix_sums[i][j], preffix_sums[i][j - 1]);
    }
  }

  cout << dp[0][0] << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tests = 1;
  // cin >> tests;

  while(tests--) 
    test_case();
}