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
const int mod = 1e9 + 7;

void add_self(int& a, int b) {
  a += b;
  if(a >= mod) {
    a -= mod;
  }
}

//Returns for every index, leftmost index to right of it 
//having a value strictly greater than itself
vector<int> next_greater(const vector<int>& values) {
  int n = values.size();
  vector<int> res(n, n);

  stack<int> pq;
  for(int i = n - 1; i >= 0; --i) {
    while(!pq.empty() && values[i] >= values[pq.top()])
      pq.pop();

    if(!pq.empty())
      res[i] = pq.top();

    pq.push(i);
  }

  return res;
}

void test_case() {
  int N;
  cin >> N;
  vector<int> A(N);
  for(auto &a : A)
    cin >> a;

  vector<int> ng = next_greater(A);

  vector<int> dp(N + 2);

  dp[N-1] = A[N-1];

  for(int i = N - 2; i >= 0; --i) {
    int l = ng[i] - i;
    int x = (l * (l + 1) / 2) % mod;

    dp[i] = (A[i] * x) % mod;
    add_self(dp[i], dp[i + l]);
    add_self(dp[i], ((l * (N - i - l) % mod) * A[i]) % mod);
  }

  int ans = 0;
  for(int i = 0; i < N; ++i)
    add_self(ans, dp[i]);

  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tests = 1;
  cin >> tests;

  while(tests--) 
    test_case();
}