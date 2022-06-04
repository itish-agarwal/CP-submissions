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

int longest(string s) {
  int n = s.size();
  vector<int> dp(n, 1);
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < i; ++j)
      if(s[i] >= s[j])
        dp[i] = max(dp[i], dp[j]+1);

  return *max_element(dp.begin(), dp.end());
}

const int ALPHABET = 26;

void test_case() {
  int N;
  string S;
  cin >> N >> S;

  vector<vector<int>> preffix_sum(ALPHABET, vector<int> (N));
  for(int i = 0; i < ALPHABET; ++i)
    for(int j = 0; j < N; ++j)
      preffix_sum[i][j] = (j > 0 ? preffix_sum[i][j-1] : 0) + (S[j] - 'A' == i);

  int Q;
  cin >> Q;
  for(int q = 0; q < Q; ++q) {
    int L, R, K;
    cin >> L >> R >> K;
    --L, --R;

    vector<int> cnt(ALPHABET);
    for(int i = 0; i < ALPHABET; ++i)
      cnt[i] = preffix_sum[i][R] - (L > 0 ? preffix_sum[i][L-1] : 0);

    if(*max_element(cnt.begin(), cnt.end()) > K) {
      cout << "No" << '\n';
      continue;
    }
    if(accumulate(cnt.begin(), cnt.end(), 0) < K) {
      cout << "No" << '\n';
      continue;
    }

    string total = "";
    for(int i = 0; i < ALPHABET; ++i)
      for(int j = 0; j < cnt[i]; ++j)
        total.push_back(char(i + 'A'));

    // debug(total);
    int len = R - L + 1;
    string later = total.substr(K);
    string first = total.substr(0, K);
    reverse(later.begin(), later.end());
    string ans = later + first;

    for(int i = ALPHABET - 1; i >= 0; --i)
      if(cnt[i] == K) {
        ans = total;
        reverse(ans.begin(), ans.end());
        break;
      }

    cout << "Yes" << '\n' << ans << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tests = 1;
  cin >> tests;

  while(tests--) 
    test_case();
}