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

template <class T>
struct SparseTable_min {
public:
  int N;
  vector<int> compute;
  vector<vector<T>> tab;

  T merge(const T& a, const T& b) {
    return min(a, b);
  }

  SparseTable_min(const vector<T>& values) {
    int N = values.size();
    compute.resize(N + 1);
    for(int i = 2; i <= N; ++i) 
      compute[i] = compute[i / 2] + 1;

    const int log = 32 - __builtin_clz(N);
    tab.resize(log);

    tab[0] = values;
    for(int j = 1; j < log; ++j) {
      tab[j].resize(N - (1 << j) + 1);
      for(int i = 0; i <= N - (1 << j); ++i)
        tab[j][i] = merge(tab[j-1][i], tab[j-1][i + (1 << (j-1))]);
    }
  }

  T query(int L, int R) {
    int j = compute[R - L + 1];
    return merge(tab[j][L], tab[j][R - (1 << j) + 1]);
  }
};

template <class T>
struct SparseTable_max {
public:
  int N;
  vector<int> compute;
  vector<vector<T>> tab;

  T merge(const T& a, const T& b) {
    return max(a, b);
  }

  SparseTable_max(const vector<T>& values) {
    int N = values.size();
    compute.resize(N + 1);
    for(int i = 2; i <= N; ++i) 
      compute[i] = compute[i / 2] + 1;

    const int log = 32 - __builtin_clz(N);
    tab.resize(log);

    tab[0] = values;
    for(int j = 1; j < log; ++j) {
      tab[j].resize(N - (1 << j) + 1);
      for(int i = 0; i <= N - (1 << j); ++i)
        tab[j][i] = merge(tab[j-1][i], tab[j-1][i + (1 << (j-1))]);
    }
  }

  T query(int L, int R) {
    int j = compute[R - L + 1];
    return merge(tab[j][L], tab[j][R - (1 << j) + 1]);
  }
};

const int INF = 2e7 + 7;

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
pair<int, int> intersection(const pair<int, int>& a, const pair<int, int>& b) {
   return make_pair(max(a.first, b.first), min(a.second, b.second));
}

void test_case() {
   int N, D;
   cin >> N >> D;

   vector<pair<int, int>> intervals(N);
   for(auto &[a, b] : intervals)
      cin >> a >> b;

   sort(intervals.begin(), intervals.end());
   vector<int> ends, starts;

   for(auto [a, b] : intervals) {
      ends.push_back(b);
      starts.push_back(a);
   }

   SparseTable_min mn(ends);
   SparseTable_max mx(starts);

   vector<int> max_reach(N);
   iota(max_reach.begin(), max_reach.end(), 0);

   for(int i = N - 1; i >= 0; --i) {
      int lo = i, hi = N - 1;
      while(lo <= hi) {
         int mid = (lo + hi) / 2;
         int min_end = mn.query(i, mid);
         int max_start = mx.query(i, mid);
         if(max_start - min_end < D) {
            max_reach[i] = mid;
            lo = mid + 1;
         }
         else {
            hi = mid - 1;
         }
      }
   }  

   segtree tree(N + 1);
   tree.update(1, 0, N, N, 0);

   vector<int> dp(N + 1, INF);
   dp[N] = 0;

   for(int i = N - 1; i >= 0; --i) {
      dp[i] = 1 + tree.query(1, 0, N, i + 1, max_reach[i] + 1);
      tree.update(1, 0, N, i, dp[i]);
   }

   cout << dp[0] << '\n';
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   int tests = 1;
   // cin >> tests;

   while(tests--)
      test_case();
}