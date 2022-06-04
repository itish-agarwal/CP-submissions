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
 
vector<int> topological_sort(const vector<vector<int>>& edges) {
  int n = edges.size();
  vector<int> in_degree(n);
  vector<int> order;
 
  for(int i = 0; i < n; ++i) 
    for(int lead : edges[i]) 
      in_degree[lead]++;
 
  for(int i = 0; i < n; ++i) 
    if(in_degree[i] == 0) 
      order.push_back(i);
 
  int cur = 0;
 
  while(cur < (int) order.size()) {
    int a = order[cur++];
 
    for(int b : edges[a])
      if(--in_degree[b] == 0)
        order.push_back(b);
  }
 
  return order;
}
 
void test_case() {
  int N;
  cin >> N;
 
  vector<vector<int>> edges(N);
  for(int i = 0; i < N; ++i) {
    int k, a;
    cin >> k;
    for(int j = 0; j < k; ++j) {
      cin >> a;
      edges[--a].push_back(i);
    }
  }
 
  vector<int> order = topological_sort(edges);
  if((int) order.size() < N) {
    cout << -1 << '\n';
    return;
  }
 
  vector<int> location(N);
  for(int i = 0; i < N; ++i)
    location[order[i]] = i;
 
  vector<int> dp(N);
 
  for(int i = 0; i < N; ++i) {
    int a = order[i];
    for(int b : edges[a]) {
      int j = location[b];
      dp[j] = max(dp[j], dp[i] + (a > b));
    }
  }
 
  cout << *max_element(dp.begin(), dp.end()) + 1 << '\n';
} 
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int tests = 1;
  cin >> tests;
  while(tests--)
    test_case();
 
}