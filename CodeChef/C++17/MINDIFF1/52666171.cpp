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
  for(int i = 0; i < (int) v.size(); ++i) { pr(v[i] + 1); cout << (i + 1 < (int) v.size() ? " " : ""); }
}
template <class T> void pr(const set<T>& pq) {
  vector<T> values(pq.begin(), pq.end()); pr(values);
}
template <class T, class... V> void pr(T t, V... v) {
  pr(t); if(sizeof...(v)) cout << " | ";
  pr(v...);
}
//Global space begins

template <class T> 
ostream& operator << (ostream& stream, const vector<T>& values) {
  for(T v : values) 
    cout << v << " ";

  return stream;
}
template <class T>
void print_vector(const vector<T>& values, int from = -1, int to = -1) {
  if(from < 0) from = 0;
  if(to < 0) to = int(values.size()) - 1;

  for(int i = from; i <= to; ++i) 
    cout << values[i] << (i < to ? ' ' : '\n');
}

void test_case() {
  int N, M;
  cin >> N >> M;

  vector<int> d(N);
  vector<vector<int>> edges(N);
  for(int r = 0; r < M; ++r) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    d[a] += 1;
    d[b] += 1;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }

  set<pair<int, int>> q;
  for(int a = 0; a < N; ++a)
    q.insert({d[a], a});

  vector<int> assignment(N, -1);
  int iter = N;

  while(!q.empty()) {
    auto f = q.begin();
    q.erase(q.begin());

    int node = f -> second;
    int val = f -> first;

    assignment[node] = iter--;

    for(int b : edges[node]) {
      if(assignment[b] == -1) {
        q.erase({d[b], b});
        d[b]--;
        q.insert({d[b], b});
      }
    }
  }

  // vector<int> per(N);
  // iota(per.begin(), per.end(), 0);
  // sort(per.begin(), per.end(), [&](const int &a, const int &b) {
  //   return d[a] < d[b];
  // });

  // debug(per);

  // for(int a = 0; a < N; ++a) 
  //   sort(edges[a].begin(), edges[a].end(), [&](const int &x, const int &y) {
  //     return d[x] < d[y];
  //   }); 

  // int lowest_degree = d[per[0]];

  // vector<int> assignment(N, -1);
  // queue<int> q;
  // int iter = N;

  // for(int a = 0; a < N; ++a)
  //   if(d[a] == lowest_degree) {
  //     assignment[a] = iter--;
  //     q.push(a);
  //   }

  // while(!q.empty()) {
  //   int a = q.front();
  //   q.pop();

  //   for(int b : edges[a]) {
  //     if(assignment[b] == -1) {
  //       assignment[b] = iter--;
  //       q.push(b);
  //     }
  //   }
  // }

  // for(int a = 0; a < N; ++a)
  //   if(assignment[per[a]] == -1) {
  //     assignment[per[a]] = iter--;
  //     q.push(per[a]);
  //   }

  // while(!q.empty()) {
  //   int a = q.front();
  //   q.pop();

  //   for(int b : edges[a]) {
  //     if(assignment[b] == -1) {
  //       assignment[b] = iter--;
  //       q.push(b);
  //     }
  //   }
  // }

  int val = 0;
  for(int a = 0; a < N; ++a) {
    int dd = 0;

    for(int b : edges[a]) 
      dd += assignment[b] < assignment[a];
    
    val = max(val, dd);
  }

  cout << val << '\n';
  print_vector(assignment);
} 

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tests = 1;
  cin >> tests;

  while(tests--) 
    test_case();
}
