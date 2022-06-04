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
const int block_size = 100;

struct Query {
  int l, r, index, mod;
  Query(int L, int R, int Index, int Mod) {
    l = L, r = R, index = Index, mod = Mod;
  }
  bool operator < (Query other) const {
    pair<int, int> p = make_pair(l, r);
    pair<int, int> q = make_pair(other.l, other.r);
    if(p.first / block_size != q.first / block_size)
      return p < q;

    return (p.first / block_size & 1) ? (p.second < q.second) : (p.second > q.second);
  }
};

int dp[102][10001];
const int nax = 3e5 + 7;

template <class T = long long>
struct fenwick_tree {
  int n;
  vector<T> tree, values;

  fenwick_tree(int _n) {
    n = _n;
    values.resize(n);
    tree.resize(n + 1);
  }

  fenwick_tree(const vector<T>& _values) {
    n = (int) values.size();
    values = _values;
    tree.resize(n + 1);
    for (int i = 0; i < n; ++i) 
      set_value(i, values[i]);
  }

  void add_value(int id, const T& delta) {
    values[id] += delta;
    for (int x = id + 1; x <= n; x += x & -x)
      tree[x] += delta;
  }

  void set_value(int id, const T& val) {
    T prev_val = values[id];
    add_value(id, val - prev_val);
    values[id] = val;
  }

  T get_value(int id) {
    return values[id];
  }

  T query(int r) {
    T res = 0;
    for (int x = r + 1; x > 0; x -= x & -x)
      res += tree[x];
    return res;
  }

  T query(int l, int r) {
    return query(r) - query(l - 1);
  }
};

void test_case() {  
   int N;
   cin >> N;

   vector<int> A(N);
   for (auto &a : A)
      cin >> a;  

   vector<int> psum = A;
   for (int i = 1; i < N; ++i)
      psum[i] += psum[i-1];

   for (int m = 1; m < 100; ++m)
      for (int i = 0; i < N; ++i)
         dp[m][i] = (i > 0 ? dp[m][i-1] : 0) + (A[i] % m);

   int Q;
   cin >> Q;

   vector<Query> queries;
   for (int q = 0; q < Q; ++q) {
      int l, r, mod;
      cin >> l >> r >> mod;
      queries.push_back(Query(--l, --r, q, mod));
   }

   sort(queries.begin(), queries.end());
   vector<int> result(Q);
   int L = 0, R = -1;

   fenwick_tree<long long> sum(nax), cnt(nax);

   for (auto q : queries) {
      int l = q.l, r = q.r, in = q.index, mod = q.mod;
      if (mod < 100) {
         result[in] = dp[mod][r] - (l > 0 ? dp[mod][l-1] : 0);
      }

      else if(mod > 10000) {
         result[in] = psum[r] - (l > 0 ? psum[l-1] : 0);
      }

      else {
         while(L > l) {
            --L;
            sum.add_value(A[L], A[L]);
            cnt.add_value(A[L], 1);
         }

         while(R < r) {
            ++R;
            sum.add_value(A[R], A[R]);
            cnt.add_value(A[R], 1);
         }

         while(L < l) {
            sum.add_value(A[L], -A[L]);
            cnt.add_value(A[L], -1);
            ++L;
         }

         while(R > r) {
            sum.add_value(A[R], -A[R]);
            cnt.add_value(A[R], -1);
            --R;
         }

         for(int x = 0; x * mod <= 100000; ++x) {
            int st = mod * x, en = mod * (x + 1) - 1;
            int sum_of_numbers = sum.query(st, en);
            int count_of_numbers = cnt.query(st, en);
            // debug(x, sum_of_numbers, count_of_numbers, st, en);
            result[in] += sum_of_numbers - x * count_of_numbers * mod;
         }
      }
   }

   for (auto &r : result)
      cout << r << '\n';
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int tests = 1;
   cin >> tests;

   while(tests--)
      test_case();
}