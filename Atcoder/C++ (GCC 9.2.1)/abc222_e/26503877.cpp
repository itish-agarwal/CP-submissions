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

long long power(long long a, long long b) {
  if(b == 0) 
    return 1;
 
  long long res = power(a, b / 2);
  res = (res * res) % mod;
  if(b % 2) 
    res = (res * a) % mod;
 
  return res;
}

template <class T>
struct SparseTable {
public:
  int N;
  vector<int> compute;
  vector<vector<T>> tab;
  vector<T> values, comparator;

  T merge(const T& a, const T& b) {
    return (comparator[a] < comparator[b] ? a : b);
  }

  SparseTable(const vector<T>& _values = {}, const vector<T>& depths = {}) {
    if(!_values.empty()) 
      build(_values, depths);
  }

  void build(const vector<T>& _values, const vector<T>& depths) {
    values = _values;
    comparator = depths;
    N = _values.size();
    compute.resize(N + 1);
    for(int i = 2; i <= N; ++i)
      compute[i] = compute[i/2] + 1;

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
struct LCA {
  int n = 0, root = 0;
  vector<vector<int>> edges;
  vector<int> parent, depth, subtree_size;
  vector<int> euler2, euler, first_occurence;
  SparseTable<int> st;

  LCA(int _n, int _root) {
    n = _n;
    root = _root;
    edges.assign(n, {});
    parent.resize(n);
    depth.resize(n);
    subtree_size.resize(n);
    first_occurence.assign(n, -1);
  }

  LCA(const vector<vector<int>>& adj, int root) {
    LCA((int) adj.size(), root);
    edges = adj;
  }

  void add_edge(int a, int b) {
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  void build() {
    function<void(int, int)> Dfs = [&](int a, int pr) {
      euler2.push_back(a);
      euler.push_back(a);
      subtree_size[a] = 1;
      parent[a] = pr;
      for(int b : edges[a]) {
        if(b != pr) {
          depth[b] = depth[a] + 1;
          parent[b] = a;
          Dfs(b, a);
          euler2.push_back(a);
        }
      }
      euler.push_back(a);
    };

    Dfs(root, -1);

    // euler2.size() != 2 * N in general 
    for(int i = 0; i < (int) euler2.size(); ++i)
      if(first_occurence[euler2[i]] == -1) 
        first_occurence[euler2[i]] = i;

    st.build(euler2, depth);
  }

  int get_lca(int a, int b) {
    a = first_occurence[a];
    b = first_occurence[b];

    if(a > b)
      swap(a, b);

    return st.query(a, b);
  }
};

vector<int> values;
int target;

void test_case() {
  int N, M, K;
  cin >> N >> M >> K;

  vector<int> sequence(M);
  for(auto &s : sequence) {
    cin >> s;
    --s;
  }

  map<pair<int, int>, int> freq;

  LCA lca(N, 0);
  for(int i = 0; i < N - 1; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    lca.add_edge(a, b);
    freq[{min(a, b), max(a, b)}] = 0;
  }

  lca.build();
 
  int st = sequence[0];
  for(int i = 1; i < M; ++i) {
    int en = sequence[i];

    int L = lca.get_lca(st, en);

    int x = st, y = en;
    while(x != L) {
      int p = lca.parent[x];
      freq[{min(x, p), max(x, p)}]++;
      x = p;
    }

    while(y != L) {
      int p = lca.parent[y];
      freq[{min(y, p), max(y, p)}]++;
      y = p;
    }

    st = en;
  }

  for(auto it : freq)
    if(it.second > 0)
      values.push_back(it.second);

  //debug(values);

  int sum = accumulate(values.begin(), values.end(), 0), n = N;
  if(sum % 2 != abs(K) % 2 || sum < abs(K)) {
    cout << 0 << '\n';
    return;
  }

  int x = (sum + abs(K)) / 2;
  target = max(sum - x, x);

  N = values.size();
  vector<vector<int>> dp(N + 1, vector<int> (target + 1));

  for(int i = N; i >= 0; --i) {
    for(int j = 0; j <= target; ++j) {
      if(i == N) {
        dp[i][j] = j == target;
        continue;
      }
      dp[i][j] = dp[i + 1][j];
      if(j + values[i] <= target) {
        add_self(dp[i][j], dp[i + 1][j + values[i]]);
      }
    }
  }

  long long rem = n - 1 - values.size();
  rem = power(2LL, rem);

  cout << (dp[0][0] * rem) % mod << '\n';
} 

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tests = 1;

  while(tests--) 
    test_case();
}
