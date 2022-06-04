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

bool delete_one(const string &w1, const string &w2) {
  int n = w1.size();
  for(int i = 0; i < n; ++i) {
    string s = w1;
    s.erase(i, 1);
    if(s == w2) {
      return true;
    }
  }

  return false;
}
bool hop(const string &w1, const string &w2) {
  int n = w1.size(), m = w2.size();
  if(m == n) {
    for(int i = 0; i < n; ++i) {
      for(int j = i + 1; j < n; ++j) {
        if(w1[j] > w1[i]) {
          string s = w1;
          s[i] = s[j];
          if(s == w2) {
            return true;
          }
        }
      }
    }

    return false;
  }

  if(m == n - 1) {
    return delete_one(w1, w2);
  }

  return false;
}

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

  vector<string> S(N);
  for (auto& s : S)
    cin >> s;

  vector<vector<int>> edges(N);

  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      if (hop(S[i], S[j])) {
        edges[i].push_back(j);
      }
      if (hop(S[j], S[i])) {
        edges[j].push_back(i);
      }
    }
  }

  vector<int> order = topological_sort(edges);
  vector<int> location(N);

  for (int i = 0; i < N; ++i)
    location[order[i]] = i;

  vector<int> dp(N, 1);

  for (int i = N - 2; i >= 0; --i) {
    int a = order[i];
    for (int b : edges[a]) {
      int in = location[b];
      dp[i] = max(dp[i], dp[in] + 1);
    }
  }

  cout << *max_element(dp.begin(), dp.end()) << '\n';
} 

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tests = 1;
  // cin >> tests;
  while(tests--)
    test_case();

}