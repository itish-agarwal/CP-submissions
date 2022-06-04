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
const int nax = 2e5 + 7;
const int inf = (int) 2e17 + 9;
 
struct node {
   int maxi, lsum, rsum, sum;
   node(int a = 0, int b = 0, int c = 0, int d = 0) {
      maxi = a;
      lsum = b;
      rsum = c;
      sum = d;
   }
};
 
struct segtree {
   vector<node> t;
   segtree(int n = nax) {
      t.resize(4*n);
   }
   node merge (node& a, node& b) {
      node ans;
      ans.maxi = max(max(a.maxi, b.maxi), a.rsum + b.lsum);
      ans.lsum = max(a.lsum, a.sum + b.lsum);
      ans.rsum = max(b.rsum, b.sum + a.rsum);
      ans.sum = a.sum + b.sum;
      return ans;
   }
   void update (int id, int l, int r, int pos, int val) {
      if(l == r) {
         t[id] = node(val, val, val, val);
         return;
      }
      int mid = (l + r) / 2;
      if(pos <= mid) 
         update(2*id, l, mid, pos, val);
      else 
         update(2*id+1, mid+1, r, pos, val);
      
      t[id] = merge(t[2*id], t[2*id+1]);
   }
   node q (int id, int l, int r, int lq, int rq) {
      if (lq > r || l > rq) 
         return node (-inf, -inf, -inf, -inf);
 
      if (lq <= l && r <= rq)
         return t[id];
 
      int mid = (l + r) / 2;
      node x = q (2 * id, l, mid, lq, rq);
      node y = q (2 * id + 1, mid + 1, r, lq, rq);
 
      // if ()
 
      return merge (x, y);
   }
};
 
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
 
vector<int> previous_greater(const vector<int>& values) {
  int n = values.size();
  vector<int> res(n, -1);
 
  stack<int> pq;
  for(int i = 0; i < n; ++i) {
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
   for (auto &a : A)
      cin >> a;
 
   segtree tree(N);
   for (int i = 0; i < N; ++i)
      tree.update (1, 0, N - 1, i, A[i]);
 
   vector<int> nxt = next_greater (A);
   vector<int> prev = previous_greater (A);
 
   for (int i = 0; i < N; ++i) {
      int l = prev[i] + 1, r = nxt[i] - 1;
      int max_sum = tree.q (1, 0, N - 1, l, r).maxi;
      // cout << max_sum << endl;
      if (max_sum > A[i]) {
         cout << "NO" << '\n';
         return;
      }
   }
 
   cout << "YES" << '\n';
}  
 
signed main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
 
   int tests = 1;
   cin >> tests;
 
   while(tests--)
      test_case();
}