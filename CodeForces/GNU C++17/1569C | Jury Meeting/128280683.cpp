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
const int nax = 2e5 + 7;
 
void add_self(int& a, int b) {
  a += b;
  if(a >= mod) {
    a -= mod;
  }
}
 
int fac[nax];
int power(int a, int b) {
  if(b == 0) 
    return 1;
 
  int res = power(a, b / 2);
  res = (res * res) % mod;
  if(b % 2) 
    res = (res * a) % mod;
 
  return res;
}
int nCr(int n, int r) {
  int p = fac[n];
  int q = (fac[r] * fac[n-r]) % mod;
 
  q = power(q, mod - 2);
  return (p * q) % mod;
}
void test_case() {
  int N;
  cin >> N;
 
  map<int, int> ff;
  vector<int> A(N);
 
  for(auto &a : A) {
    cin >> a;
    ff[a] += 1;
  }
 
  sort(A.begin(), A.end());
 
  // for(int i = 1; i < N; ++i) {
  //   if(A[i] > A[i-1] + 1) {
  //     cout << 0 << '\n';
  //     return;
  //   }
  // }
 
  int ans = fac[N];
 
  if(ff[A[N-1]] > 1) {
    cout << ans << '\n';
    return;
  }
 
  if(A[N-1] - A[N-2] >= 2) {
    cout << 0 << '\n';
    return;
  }
 
  int sub = nCr(N, 1 + ff[A[N-2]]);
  // debug(sub);
  sub = (sub * fac[N - 1 - ff[A[N-2]]]) % mod;
  sub = (sub * fac[ff[A[N-2]]]) % mod;
 
  cout << (ans - sub + mod) % mod << '\n';
} 
 
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  fac[0] = 1;
  for(int i = 1; i < nax; ++i)
    fac[i] = (i * fac[i-1]) % mod;
 
  int tests = 1;
  cin >> tests;
  while(tests--)
    test_case();
 
}