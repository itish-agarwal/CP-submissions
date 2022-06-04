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
const int INF = 2e17 + 7;
const int MAX_N = 1e5 + 7;

vector<int> edges[MAX_N];
int A[MAX_N], dp[MAX_N], vis[MAX_N];

int Dfs(int a, int pr, int turn) {

  if(vis[a])
    return dp[a];

  bool is_leaf = true;
  int res = (turn == 0 ? INF : -INF);

  for(int b : edges[a]) {
    if(b != pr) {
      is_leaf = false;
      int x = Dfs(b, a, turn ^ 1);
      if(turn == 0)
        res = min(res, A[b] + x);

      else 
        res = max(res, A[b] + x);
    }
  }

  if(is_leaf) 
    res = 0;

  vis[a] = 1;
  return dp[a] = res;
}

void test_case() {
  int N, K;
  cin >> N >> K;

  for(int i = 0; i < N; ++i)
    cin >> A[i];

  for(int i = 0; i <= N; ++i)
    edges[i].clear();

  for(int i = 0; i < N - 1; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  memset(vis, 0, sizeof(vis));
  cout << Dfs(0, -1, 0) << '\n';
} 

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tests = 1;
  cin >> tests;
  while(tests--)
    test_case();

}