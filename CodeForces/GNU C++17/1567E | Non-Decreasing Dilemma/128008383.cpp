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
 
struct segment {
  long long count;
  int length, preffix_best, suffix_best;
  int first, last;
 
  segment(int init = -1, int L = 0) {
    first = last = init;
    length = preffix_best = suffix_best = count = L;
  }
};
 
segment merge(const segment& L, const segment& R) {
  segment ans;
 
  ans.count = L.count + R.count;
  if(L.last <= R.first)
    ans.count += (long long) L.suffix_best * R.preffix_best;
 
  ans.length = L.length + R.length;
 
  ans.preffix_best = L.preffix_best;
  if(L.preffix_best == L.length && L.last <= R.first) 
    ans.preffix_best = L.length + R.preffix_best;
 
  ans.suffix_best = R.suffix_best;
  if(R.suffix_best == R.length && L.last <= R.first)
    ans.suffix_best = R.length + L.suffix_best;
 
  ans.first = L.first;
  ans.last = R.last;
  return ans;
}
 
struct segtree {
  vector<segment> t;
  segtree(int _n) {
    t.resize(4 * _n);
  }
 
  void update(int id, int l, int r, int pos, int val) {
    if(l == r) {
      t[id] = segment(val, 1);
      return;
    }
 
    int m = (l + r) >> 1;
    if(pos <= m)
      update(id<<1, l, m, pos, val);
    else
      update(id<<1 | 1, m + 1, r, pos, val);
 
    t[id] = merge(t[id<<1], t[id<<1 | 1]);
  }
  segment query(int id, int l, int r, int lq, int rq) {
    if(lq > r || l > rq) 
      return segment();
 
    if(lq <= l && r <= rq) 
      return t[id];
 
    int m = (l + r) >> 1;
    segment L = query(id<<1, l, m, lq, rq);
    segment R = query(id<<1 | 1, m + 1, r, lq, rq);
    return merge(L, R);
  }
};
 
void test_case() {
  int N, Q;
  cin >> N >> Q;
 
  segtree tree(N);
  for(int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    tree.update(1, 0, N - 1, i, a);
  }
 
  for(int q = 0; q < Q; ++q) {
    int tt;
    cin >> tt;
    if(tt == 1) {
      int in, val;
      cin >> in >> val;
      tree.update(1, 0, N - 1, --in, val);
    }
 
    else {
      int l, r;
      cin >> l >> r;
      --l, --r;
 
      cout << tree.query(1, 0, N - 1, l, r).count << '\n';
    }
  }
} 
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  test_case();
}