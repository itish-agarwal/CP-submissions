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
const int INF = 2e8 + 7;
 
struct segtree {
  vector<int> t;
  segtree(int _n) {
    t.assign(4 * _n, INF); //
  }
 
  int merge(const int& a, const int& b) {
    return min(a, b); //
  }
 
  void update(int id, int l, int r, int pos, int val) {
    if(l == r) {
      t[id] = val;
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
      return INF; //
 
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
 
  vector<int> A(N), B(N);
  map<int, int> la, lb;
 
  for(int i = 0; i < N; ++i) {
    cin >> A[i];
    A[i] -= 1;
    la[A[i]] = i;
  }
 
  for(int i = 0; i < N; ++i) {
    cin >> B[i];
    B[i] -= 1;
    lb[B[i]] = i;
  } 
 
  int ans = 2e9 + 7;
 
  segtree tree(2 * N);
  for(int i = 1; i < 2 * N; i += 2) 
    tree.update(1, 0, 2 * N - 1, i, lb[i]);
 
  for(int i = 0; i < 2 * N; i += 2) {
    int candidate = la[i];
    candidate += tree.query(1, 0, 2 * N - 1, i + 1, 2 * N - 1);
    ans = min(ans, candidate);
  }
 
  cout << ans << '\n';
} 
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int tests = 1;
  cin >> tests;
  while(tests--)
    test_case();
 
}