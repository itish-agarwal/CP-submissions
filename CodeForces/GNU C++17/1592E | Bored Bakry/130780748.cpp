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
const int nax = 1e7 + 10;
const int B = 20;
 
vector<vector<int>> p(nax);
 
int longest(const vector<int> &a, int bit) {
  int n = a.size();
  vector<int> dp(n);
 
  for(int i = 0; i < n; ++i) {
    dp[i] = (a[i] >> bit & 1) ? 1 : 0;
 
    if(dp[i] && i > 0) {
      dp[i] = max(dp[i], dp[i-1] + 1);
    }
  }
 
  vector<int> preffix_xor = a;
  for(int i = 1; i < n; ++i)
    preffix_xor[i] ^= preffix_xor[i-1];
 
  for(int x = 0; x < nax; ++x)
    p[x].clear();
 
  p[0].push_back(0);
 
  for(int i = 0; i < n; ++i)
    p[preffix_xor[i]].push_back(i + 1);
 
  int res = 0;
  
  for(int i = 0; i < n; ++i) {
    int j = i - dp[i] + 1;
    if(i >= j) {
      int x = preffix_xor[i];
      int in = lower_bound(p[x].begin(), p[x].end(), j) - p[x].begin();
      if(in >= 0 && in < (int) p[x].size()) {
        res = max(res, i - p[x][in] + 1);
      }
    }
  }  
 
  return res;
}
 
void test_case() {
  int N;
  cin >> N;
 
  vector<int> A(N);
  for(auto &a : A)
    cin >> a;
 
  int ans = 0, tt = (1 << B) - 1;
 
  for(int bit = 0; bit < B; ++bit) {
    ans = max(ans, longest(A, bit));
    
    for(auto &a : A)
      if(a >> bit & 1)
        a ^= 1 << bit;
  }
 
  cout << ans << '\n';
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  int tests = 1;
  // cin >> tests;
 
  while(tests--) 
    test_case();
}