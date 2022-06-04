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

const long long INF = 2e17 + 9;

void test_case() {
  int N;
  cin >> N;

  vector<int> A(N);
  for (auto &a : A)
    cin >> a;

  vector<int> S = A;
  sort(S.begin(), S.end());
  map<int, int> location;

  for(int i = 0; i < N; ++i)
    location[S[i]] = i;


  vector<pair<int, int>> lens;
  int last = 0;

  for(int i = 1; i < N; ++i) {
    if(location[A[i]] != location[A[i-1]] + 1) {
      lens.emplace_back(A[last], i - last);
      last = i;
    }
  }

  lens.emplace_back(A[last], N - last);
  sort(lens.begin(), lens.end());

  vector<int> segs;
  for (auto [a, l] : lens)
    segs.push_back(l);

  long long ans = accumulate(segs.begin(), segs.end(), 0LL);
  ans -= *max_element(segs.begin(), segs.end());

  N = segs.size();
  vector<int> preffix_sum = segs;
  for(int i = 1; i < N; ++i)
    preffix_sum[i] += preffix_sum[i - 1];

  auto sum = [&](int l, int r) {
    return preffix_sum[r] - (l > 0 ? preffix_sum[l - 1] : 0);
  };

  vector<vector<long long>> dp(N, vector<long long> (N, INF));
  
  for(int l = N - 1; l >= 0; --l) {
    for(int r = l; r < N; ++r) {
      if(l == r) {
        dp[l][r] = 0;
        continue;
      }
      for(int k = l; k < r; ++k) {
        dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + sum(l, r));
      }
    }
  }

  ans += dp[0][N - 1];
  cout << ans << '\n';
} 

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tests;
  cin >> tests;
  while(tests--)
    test_case();
}