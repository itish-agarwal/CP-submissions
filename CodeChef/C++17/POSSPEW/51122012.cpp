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

void test_case() {
  int N, K;
  cin >> N >> K;

  vector<int> A(N);
  for(auto &a : A)
    cin >> a;

  queue<int> q;
  vector<int> vis(N), time(N, -1);

  for(int i = 0; i < N; ++i)
    if(A[i] > 0) {
      time[i] = 0;
      vis[i] = 1;
      q.push(i);
    }

  if(q.empty()) {
    cout << 0 << '\n';
    return;
  }

  while(!q.empty()) {
    int u = q.front();
    q.pop();

    if(vis[(u + 1) % N] == 0) {
      time[(u + 1) % N] = time[u] + 1;
      vis[(u + 1) % N] = 1;
      q.push((u + 1) % N);
    }

    if(vis[(u - 1 + N) % N] == 0) {
      time[(u - 1 + N) % N] = time[u] + 1;
      vis[(u - 1 + N) % N] = 1;
      q.push((u - 1 + N) % N);
    }
  }

  long long ans = accumulate(A.begin(), A.end(), 0LL);

  for(int i = 0; i < N; ++i) {
    if(time[i] > -1) {
      ans += max(0LL, 2LL * (K - time[i]));
    } 
  }

  cout << ans << '\n';
} 

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tests = 1;
  cin >> tests;
  while(tests--)
    test_case();

}