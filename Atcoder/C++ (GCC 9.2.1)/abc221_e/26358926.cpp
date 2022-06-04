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

void add_self(int& a, int b) {
  a += b;
  if(a >= mod) {
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

vector<int> compress(const vector<int> &a) {
  int n = a.size();

  vector<int> b = a;
  sort(b.begin(), b.end());

  map<int, int> mp;
  int cnt = 0;

  for(auto &el : b)
    if(mp.count(el) == 0)
      mp[el] = cnt++;

  vector<int> res(n);
  for(int i = 0; i < n; ++i)
    res[i] = mp[a[i]];

  return res;
}

struct segtree {
  vector<int> t;
  segtree(int _n) {
    t.resize(4 * _n); //
  }

  int merge(const int& a, const int& b) {
    return (a + b) % mod; //
  }

  void update(int id, int l, int r, int pos, int val) {
    if(l == r) {
      t[id] += val;
      return;
    }

    int m = (l + r) >> 1;
    if(pos <= m)
      update(id<<1, l, m, pos, val);
    else
      update(id<<1 | 1, m + 1, r, pos, val);

    t[id] = merge(t[id<<1], t[id<<1 | 1]); 
  }
  int query(int id, int l, int r, int lq, int rq) {
    if(lq > r || l > rq) 
      return 0; //

    if(lq <= l && r <= rq) 
      return t[id];

    int m = (l + r) >> 1;
    int L = query(id<<1, l, m, lq, rq);
    int R = query(id<<1 | 1, m + 1, r, lq, rq);
    return merge(L, R);
  }
};

void test_case() {  
  int N;
  cin >> N;

  vector<int> A(N);
  for(auto &a : A)
    cin >> a;

  A = compress(A);
  // debug(A);

  vector<int> inverse(N);
  for(int i = 0; i < N; ++i) 
    inverse[i] = power(power(2, i), mod - 2);

  int ans = 0;
  segtree tree(N);

  tree.update(1, 0, N - 1, A[0], inverse[0]);

  for(int i = 1; i < N; ++i) {
    int num = power(2, i - 1);

    num = (num * tree.query(1, 0, N - 1, 0, A[i])) % mod;
    add_self(ans, num);

    tree.update(1, 0, N - 1, A[i], inverse[i]);
  }

  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tests = 1;
  // cin >> tests;

  while(tests--) 
    test_case();
}