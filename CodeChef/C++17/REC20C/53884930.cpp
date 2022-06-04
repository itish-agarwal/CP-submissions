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
  pr(t); if(sizeof...(v)) cout << " | "; pr(v...);
}
//Global space begins
const int MAX_N = 1e5 + 7;
const int mod = 1e9 + 7;
int fac[MAX_N];

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
  int N;
  cin >> N;

  vector<int> A(N + 1);
  for(int i = 1; i <= N; ++i)
    cin >> A[i];

  vector<int> psum(N + 2);
  int Q;
  cin >> Q;
  for(int q = 0; q < Q; ++q) {
    int l, r;
    cin >> l >> r;
    psum[l]++;
    psum[r+1]--;
  }

  for(int i = 1; i <= N + 1; ++i)
    psum[i] += psum[i-1];

  map<int, int> occur;
  for(int i = 1; i <= N; ++i)
    occur[psum[i]]++;

  vector<pair<int, int>> ret;
  for(auto it : occur)
    ret.emplace_back(it);

  sort(ret.begin(), ret.end());
  reverse(ret.begin(), ret.end());
  sort(A.rbegin(), A.rend());

  int ans = 1, iter = 0;

  for(auto [x, n] : ret) {
    ans = (ans * fac[n]) % mod;
    map<int, int> freq;
    for(int i = iter; i < iter + n; i++)
      freq[A[i]]++;

    iter += n;

    for(auto it : freq) {
      int ff = fac[it.second];
      ff = power(ff, mod - 2);
      ans = (ans * ff) % mod;
    }
  }  

  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  fac[0] = 1;
  for(int i = 1; i < MAX_N; ++i)
    fac[i] = (i * fac[i-1]) % mod;

  int tests = 1;
  cin >> tests;

  while(tests--) 
    test_case();
}