//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
using namespace chrono;

#define ordered_set tree <int,  null_type,  less_equal<int>,  rb_tree_tag,  tree_order_statistics_node_update>

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

void test_case() {
  int N, K;
  cin >> N >> K;

  vector<int> A(N * N);
  for(auto &a : A)
    cin >> a;

  sort(A.begin(), A.end());

  int before = N / 2;

  auto works = [&](int in) {
    vector<int> taken(N * N);
    int a = 0, b = in, c = N * N - 1, cost = 0;

    for(int rep = 0; rep < N; ++rep) {

      int cnt = 0;
      while(a < N * N - 1 && cnt < before) {
        cnt += !taken[a];
        taken[a] = 1;
        a++;
      }

      if(cnt < before || a == N * N) 
        return false;

      b = max(a, b);
      while(taken[b]) 
        b++;

      taken[b] = 1;

      cnt = 0;
      while(c >= 0 && cnt < before - 1) {
        cnt += !taken[c];
        taken[c] = 1;
        c--;
      }

      if(cnt < before - 1 || c < 0)
        return false;

      if(a > b || c < b)
        return false;

      cost += A[b];
    }

    return cost <= K;
  };

  int lo = before, hi = N * N - 1, ans = -1;

  while(lo <= hi) {
    int mid = (lo + hi) / 2;
    if(works(mid)) {
      lo = mid + 1;
      ans = A[mid];
    }
    else {
      hi = mid - 1;
    }
  }
  cout << ans << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tests = 1;
  cin >> tests;

  while(tests--) 
    test_case();
}
