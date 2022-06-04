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

struct node {
   int cnt[2];
   int lazy_val;
   node() {
      cnt[0] = cnt[1] = 0;
      lazy_val = 0;
   }
};

node merge(const node &a, const node &b) {
   node res;
   res.cnt[0] = a.cnt[0] + b.cnt[0];
   res.cnt[1] = a.cnt[1] + b.cnt[1];
   return res;
}

struct segtree {
   vector<node> t;
   segtree(int _n) {
      t.resize(4 * _n);
   }
   void push(int id, int l, int r) {
      if(t[id].lazy_val) {
         swap(t[id].cnt[0], t[id].cnt[1]);
         if(l ^ r) {
            t[id << 1].lazy_val ^= 1;
            t[id << 1 | 1].lazy_val ^= 1;
         }
      }
      t[id].lazy_val = 0;
   }
   void init(int id, int l, int r) {
      t[id].cnt[0] = r - l + 1;
      if(l ^ r) {
         int mid = (l + r) >> 1;
         init(id << 1, l, mid);
         init(id << 1 | 1, mid + 1, r);
      }
   }
   void update(int id, int l, int r, int lq, int rq) {
      push(id, l, r);
      if(lq > r || l > rq) {
         return;
      }
      if(lq <= l && r <= rq) {
         t[id].lazy_val ^= 1;
         push(id, l, r);
         return;
      }
      int mid = (l + r) >> 1;
      update(id << 1, l, mid, lq, rq);
      update(id << 1 | 1, mid + 1, r, lq, rq);
      t[id] = merge(t[id << 1], t[id << 1 | 1]);
   }
   node query(int id, int l, int r, int lq, int rq) {
      push(id, l, r);
      if(lq > r || l > rq) {
         return node();
      }
      if(lq <= l && r <= rq) {
         return t[id];
      }
      int mid = (l + r) >> 1;
      node x = query(id << 1, l, mid, lq, rq);
      node y = query(id << 1 | 1, mid + 1, r, lq, rq);
      return merge(x, y);
   }
};

void test_case() {
   int N, Q;
   cin >> N >> Q;

   segtree tree(N);
   tree.init(1, 0, N - 1);

   for (int q = 0; q < Q; q++) {
      int tt, l, r;
      cin >> tt >> l >> r;
      if(tt == 0) {
         tree.update(1, 0, N - 1, l, r);
      }
      else {
         cout << tree.query(1, 0, N - 1, l, r).cnt[1] << '\n';
      }
   }
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int tests = 1;
   // cin >> tests;

   while(tests--)
      test_case();
}