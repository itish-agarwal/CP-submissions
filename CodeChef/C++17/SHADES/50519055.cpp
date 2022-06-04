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

struct segtree {
  struct node {
    int sum, max_r, min_r, lazy;
    node(int a = 0, int b = 0, int c = 0, int d = 0) {
      sum = a, max_r = b, min_r = c, lazy = d;
    }
  };
  vector<node> t;
  int n;
  segtree(int _n) {
    n = _n;
    t.resize(4 * n);
  }
  node merge(const node& a, const node& b) {
    return node(a.sum + b.sum, max(a.max_r, b.max_r), min(a.min_r, b.min_r));
  } 
  void push(int id, int l, int r) {
    if(t[id].lazy) {  
      t[id].sum = (r - l + 1) - t[id].sum;
    }
    t[id].max_r += t[id].lazy;
    t[id].min_r += t[id].lazy;
    if(l != r && t[id].lazy > 0) {
      t[id<<1].lazy ^= 1;
      t[id<<1 | 1].lazy ^= 1;
    }
    t[id].lazy = 0;
  }
  void update(int id, int l, int r, int lq, int rq, int val) {
    push(id, l, r);
    if(lq > r || l > rq) {
      return;
    }

    if(lq <= l && r <= rq) {
      t[id].lazy ^= 1;
      push(id, l, r);
      return;
    }
    int m = (l + r) >> 1;
    update(id<<1, l, m, lq, rq, val);
    update(id<<1 | 1, m + 1, r, lq, rq, val);
    t[id] = merge(t[id<<1], t[id<<1 | 1]);
  } 
  node range_query(int id, int l, int r, int lq, int rq) {
    push(id, l, r);
    if(lq > r || l > rq) {
      return node();
    }
    if(lq <= l && r <= rq) {
      return t[id];
    }

    int m = (l + r) >> 1;
    node x = range_query(id<<1, l, m, lq, rq);
    node y = range_query(id<<1 | 1, m + 1, r, lq, rq);
    return merge(x, y);
  }
  int range_sum(int id, int l, int r, int lq, int rq) {
    return range_query(id, l, r, lq, rq).sum;
  }
  int range_max(int id, int l, int r, int lq, int rq) {
    return range_query(id, l, r, lq, rq).max_r;
  } 
  int range_min(int id, int l, int r, int lq, int rq) {
    return range_query(id, l, r, lq, rq).min_r;
  }

  //Returns position of first element <= x in the array
  int first_occurence(int id, int l, int r, int val) {
    int min_in_this_range = range_min(id, l, r, 0, n - 1);
    if(min_in_this_range > val) {
      return -1;
    }
    if(l == r) {
      return l;
    } 
    int m = (l + r) >> 1;
    int L = first_occurence(id<<1, l, m, val);
    if(L > -1) 
      return L;
    return first_occurence(id<<1 | 1, m + 1, r, val);
  }
  //Returns position of last element >= x in the array 
  int last_occurence(int id, int l, int r, int val) {
    int max_in_this_range = range_max(id, l, r, 0, n - 1);
    if(max_in_this_range < val) {
      return -1;
    }
    if(l == r) {
      return l;
    }
    int m = (l + r) >> 1;
    int R = last_occurence(id<<1 | 1, m + 1, r, val);
    if(R > -1) {
      return R;
    }
    return last_occurence(id<<1, l, m, val);
  }
};

void test_case() {
  int N;
  cin >> N;

  vector<vector<int>> edges(N);
  for(int i = 0; i < N - 1; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  vector<int> depth(N);
  vector<int> euler;

  function<void(int, int)> Dfs = [&](int a, int pr) {
    euler.push_back(a);
    for(int b : edges[a]) {
      if(b != pr) {
        depth[b] = depth[a] + 1;  
        Dfs(b, a);
      }
    }
    euler.push_back(a);
  };

  Dfs(0, -1);

  vector<int> beg(N, -1), en(N);
  for(int i = 0; i < 2 * N; ++i) {
    int node = euler[i];
    if(beg[node] == -1) 
      beg[node] = i;

    en[node] = i;
  }

  segtree tree(2 * N);
  tree.update(1, 0, 2 * N - 1, 0, 2 * N - 1, 1);

  int Q;
  cin >> Q;
  for(int q = 0; q < Q; ++q) {
    int tt;
    cin >> tt;
    if(tt == 1) {
      int a, b;
      cin >> a >> b;
      --a, --b;

      if(depth[a] > depth[b]) 
        swap(a, b);

      int L = beg[b], R = en[b];
      int below = tree.range_sum(1, 0, 2 * N - 1, L, R);
      below /= 2;

      int total = tree.range_sum(1, 0, 2 * N - 1, 0, 2 * N - 1);
      total /= 2;

      cout << (long long)below * (total - below) << '\n';
    }
    else {
      int a;
      cin >> a; --a;

      int L = beg[a], R = en[a];
      tree.update(1, 0, 2 * N - 1, L, R, 1);
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